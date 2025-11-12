public class Point {
    private double x;
    private double y;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void moveX(double dx) { x += dx; }
    public void moveY(double dy) { y += dy; }

    public double distanceToOrigin() {
        return Math.sqrt(x * x + y * y);
    }

    public double distanceTo(Point other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public double getRadius() { return Math.sqrt(x * x + y * y); }
    public double getAngle() { return Math.atan2(y, x); }

    public boolean equals(Point other) {
        return this.x == other.x && this.y == other.y;
    }

    public boolean notEquals(Point other) {
        return !equals(other);
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
// 2 частина коду з перевіркою 
public class Main {
    public static void main(String[] args) {
        Point A = new Point(3, 4);
        Point B = new Point(6, 8);

        System.out.println("Точка A: " + A);
        System.out.println("Точка B: " + B);

        A.moveX(2);
        A.moveY(-1);
        System.out.println("Після переміщення A: " + A);

        System.out.println("Відстань A до початку координат: " + A.distanceToOrigin());
        System.out.println("Відстань між A і B: " + A.distanceTo(B));
        System.out.println("Полярний радіус A: " + A.getRadius());
        System.out.println("Полярний кут A (у радіанах): " + A.getAngle());

        System.out.println("A і B співпадають? " + A.equals(B));
        System.out.println("A і B не співпадають? " + A.notEquals(B));
    }
}
