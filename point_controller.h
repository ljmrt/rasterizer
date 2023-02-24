#ifndef POINT_CONTROLLER_H
#define POINT_CONTROLLER_H

class point_2d
{
    private:
        int x;
        int y;
    public:
        point_2d(int source_x, int source_y);  // constructor
        // TODO point_2d(const point_2d& source_point);  // copy constructor
        // accessor functions
        int get_x();
        int get_y();
        void set_x(int source_x);
        void set_y(int source_y);
};

class line_2d
{
    private:
        point_2d point_0;
        point_2d point_1;
    public:
        line_2d(point_2d source_0, point_2d source_1);  // constructor
        line_2d(const line_2d& source_line);  // copy constructor

        // accessor functions
        point_2d get_id_point(int id);  // get point with id
        line_2d get_line();  // get the entire line
        void set_id_point(point_2d source, int id);  // set point with id
        void set_line(point_2d source_0, point_2d source_1);  // set the entire line
};

class point_3d
{
    private:
        float x;
        float y;
        float z;
    public:
        point_3d(float source_x, float source_y, float source_z);  // constructor
        // accessor functions
        float get_x();
        float get_y();
        float get_z();
        void set_x(float source_x);
        void set_y(float source_y);
        void set_z(float source_z);
};

#endif  // POINT_CONTROLLER_H
