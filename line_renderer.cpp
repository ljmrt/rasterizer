#include <cstdlib>
#include <cmath>
#include <SDL2/SDL.h>
#include "line_renderer.h"
#include "point_controller.h"
#include "common.h"
#include "color_helper.h"
#include <iostream>

void draw_line(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, rgb_color color)  // TODO: refactor and implement bresenham's algorithm
{
    SDL_SetRenderDrawColor(renderer, color.get_r(), color.get_g(), color.get_b(), 255);

    int x0 = point_0.get_x();
    int y0 = point_0.get_y();
    int x1 = point_1.get_x();
    int y1 = point_1.get_y();

    // if the change in x is bigger than the change in y(line is more horizontal)
    if (abs(x1 - x0) > abs(y1 - y0)) {
        // ensure x0 < x1
        if (x0 > x1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }

        std::vector<float> ys = interpolate(x0, y0, x1, y1);
        for (auto x = x0; x < x1; x++) {
            int ys_value = std::size_t(x - x0) < ys.size() ? ys.at(x - x0) : 0;
            canvas_draw_pixel(renderer, x, ys_value);
        }
    } else {  // line is more vertical
        // ensure y0 < y1
        if (y0 > y1) {
            std::swap(y0, y1);
            std::swap(x0, x1);
        }

        std::vector<float> xs = interpolate(y0, x0, y1, x1);
        for (auto y = y0; y < y1; y++) {
            int xs_value = std::size_t(y - y0) < xs.size() ? xs.at(y - y0) : 0;
            canvas_draw_pixel(renderer, xs_value, y);
        }
    }
}

void draw_wireframe_triangle(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2, rgb_color color)
{
    draw_line(renderer, point_0, point_1, color);
    draw_line(renderer, point_1, point_2, color);
    draw_line(renderer, point_2, point_0, color);
}

void draw_filled_triangle(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2, rgb_color color, float h0, float h1, float h2)
{
    SDL_SetRenderDrawColor(renderer, color.get_r(), color.get_g(), color.get_b(), 255);
    // ensure y0 <= y1 <= y2
    if (point_1.get_y() < point_0.get_y()) {
        std::swap(point_1, point_0);
        std::swap(h1, h0);
    }
    if (point_2.get_y() < point_0.get_y()) {
        std::swap(point_2, point_0);
        std::swap(h2, h0);
    }
    if (point_2.get_y() < point_1.get_y()) {
        std::swap(point_2, point_1);
        std::swap(h2, h1);
    }
    // proper value fetch
    int x0 = point_0.get_x();
    int y0 = point_0.get_y();
    int x1 = point_1.get_x();
    int y1 = point_1.get_y();
    int x2 = point_2.get_x();
    int y2 = point_2.get_y();

    // x and h values between two points
    std::vector<float> x_01 = interpolate(y0, x0, y1, x1);
    std::vector<float> h_01 = interpolate(y0, h0, y1, h1);
        
    std::vector<float> x_12 = interpolate(y1, x1, y2, x2);
    std::vector<float> h_12 = interpolate(y1, h1, y2, h2);
    
    std::vector<float> x_02 = interpolate(y0, x0, y2, x2);
    std::vector<float> h_02 = interpolate(y0, h0, y2, h2);

    // concatenate x_01 and x_12(short sides) and h_01 and h_12
    x_01.pop_back();
    x_01.insert(x_01.end(), x_12.begin(), x_12.end());
    h_01.pop_back();
    h_01.insert(h_01.end(), h_12.begin(), h_12.end());

    for (int i2 : h_02) {
    }

    int m = floor(x_01.size() / 2);  // middle horizontal line
    std::vector<float> x_left;  // left of horizontal line
    std::vector<float> x_right;  // right of horizontal line
    std::vector<float> h_left;
    std::vector<float> h_right;
    if (x_02.at(m) < x_01.at(m)) {
        x_left = x_02;
        h_left = h_02;

        x_right = x_01;
        h_right = h_01;
    } else {
        x_left = x_01;
        h_left = h_01;
        
        x_right = x_02;
        h_right = h_02;
    }
 
    for (int y = y0; y < y2; y++) {
        int this_x_left = x_left.at(y - y0);
        int this_x_right = x_right.at(y - y0);
        
        std::vector<float> h_segment = interpolate(this_x_left, h_right.at(y - y0), this_x_right, h_right.at(y - y0));
        for (int x = this_x_left; x < this_x_right; x++) {
            rgb_color shaded_color = multiply_color(color, h_segment.at(x - this_x_left));
            SDL_SetRenderDrawColor(renderer, shaded_color.get_r(), shaded_color.get_g(), shaded_color.get_b(), 255);

            canvas_draw_pixel(renderer, x, y);
        }
    }
}
