

public class QuadraticEquation {
    private double a;
    private double b;
    private double c;

    // Конструктор
    public QuadraticEquation(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    // Метод обчислення к-cті коренів
    public int numberOfRoots() {
        double D = b * b - 4 * a * c; // дискримінант

        if (a == 0) {
            //  рівняння лінійне 
            return (b != 0) ? 1 : 0;
        }

        if (D > 0) return 2;
        else if (D == 0) return 1;
        else return 0;
    }

    //  Метод обчислення самих коренів
    public double[] getRoots() {
        if (a == 0) { // рівняння лінійне
            if (b == 0) return null; // немає коренів
            return new double[]{ -c / b }; // один корінь
        }

        double D = b * b - 4 * a * c;

        if (D < 0) {
            return null; // немає дійсних коренів
        } else if (D == 0) {
            double x = -b / (2 * a);
            return new double[]{ x };
        } else {
            double sqrtD = Math.sqrt(D);
            double x1 = (-b + sqrtD) / (2 * a);
            double x2 = (-b - sqrtD) / (2 * a);
            return new double[]{ x1, x2 };
        }
    }

    
    @Override
    public String toString() {
        return a + "x² + " + b + "x + " + c + " = 0";
    }
}
// 2га чпстина коду з перевіркою 
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Приклад 1
        QuadraticEquation eq1 = new QuadraticEquation(1, -3, 2); // x² - 3x + 2 = 0
        System.out.println("Рівняння: " + eq1);
        System.out.println("Кількість коренів: " + eq1.numberOfRoots());
        System.out.println("Корені: " + Arrays.toString(eq1.getRoots()));
        System.out.println();

        // Приклад 2
        QuadraticEquation eq2 = new QuadraticEquation(1, 2, 5); // x² + 2x + 5 = 0
        System.out.println("Рівняння: " + eq2);
        System.out.println("Кількість коренів: " + eq2.numberOfRoots());
        System.out.println("Корені: " + Arrays.toString(eq2.getRoots()));
        System.out.println();

        // Приклад 3 (лінійне рівняння)
        QuadraticEquation eq3 = new QuadraticEquation(0, 4, -8); // 4x - 8 = 0
        System.out.println("Рівняння: " + eq3);
        System.out.println("Кількість коренів: " + eq3.numberOfRoots());
        System.out.println("Корені: " + Arrays.toString(eq3.getRoots()));
    }
}

