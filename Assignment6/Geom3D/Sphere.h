class Sphere{
    public:
    Sphere(int radius, int cx, int cy, int cz);
        
    static const int longitude = 50;
    static const int latitude = 50;
    
    double radius;
    double center[3];
    double color[3];
};
