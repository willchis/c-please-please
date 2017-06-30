class Point2d {
    public:
        Point2d(double x = 0.0, double y = 0.0);
        double getX();
        double getY();
        double distanceTo(Point2d point);
        void print();
    private:
        double m__x;
        double m__y;
};