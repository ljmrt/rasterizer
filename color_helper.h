#ifndef COLOR_HELPER_H
#define COLOR_HELPER_H

class rgb_color
{
    private:
        float r;  // red intensity of color
        float g;  // green intensity of color
        float b;  // blue intensity of color
    public:
        rgb_color();
        rgb_color(float source_r, float source_g, float source_b);
        // accessor functions
        float get_r();
        float get_g();
        float get_b();
        void set_r(float source_r);
        void set_g(float source_g);
        void set_b(float source_b);
    
};

// multiply a color by a constant
//
// @param source_color color to multiply
// @param constant constant to multiply by
rgb_color multiply_color(rgb_color source_color, float constant);

#endif  // COLOR_HELPER_H
