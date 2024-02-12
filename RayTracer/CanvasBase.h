#pragma once

#include <SDL.h>
#include <stdexcept>
#include "Vec.h"
#include "Color.h"

class CanvasBase {
public:
	CanvasBase(const char* window_title, size_t width, size_t height) 
		: _width(width)
		, _height(height)
	{

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			throw std::runtime_error(std::string("Could not initialize sdl2: " )+ SDL_GetError());

		_window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			static_cast<int>(width), static_cast<int>(height), SDL_WINDOW_SHOWN);

		if (_window == nullptr)
			throw std::runtime_error(std::string("Could not create window: ") + SDL_GetError());

		_renderer = SDL_CreateRenderer(_window, -1, 0);

		if (_renderer == nullptr)
			throw std::runtime_error(std::string("Could not create renderer: ") + SDL_GetError());
	}

	CanvasBase(CanvasBase const&) = delete;
	CanvasBase& operator = (CanvasBase const&) = delete;

	CanvasBase(CanvasBase const&&) = delete;
	CanvasBase& operator = (CanvasBase const&&) = delete;
	
	virtual ~CanvasBase() 
	{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);

	}

	void put_pixel(const Vec2i& pt, const Color& color) const 
	{
		SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, 255);
		SDL_RenderDrawPoint(_renderer,
			(static_cast<int>(_width) / 2) + pt.x,
			(static_cast<int>(_height) / 2) - pt.y - 1);
	}

	virtual void clear()  
	{
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
		SDL_RenderClear(_renderer);
	}

	void present() const
	{
		SDL_RenderPresent(_renderer);
	}

protected:
	const size_t _width;
	const size_t _height;
private:
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
};
