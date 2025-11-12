import java.util.*;

public class MergeSortedArrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //  Введення розмірів масивів
        System.out.print("Введіть розмір першого масиву: ");
        int n = sc.nextInt();
        System.out.print("Введіть розмір другого масиву: ");
        int m = sc.nextInt();

        int[] A = new int[n];
        int[] B = new int[m];

        Random rand = new Random();

        // випадкові числ
        for (int i = 0; i < n; i++) {
            A[i] = rand.nextInt(100); // числ 0–99
        }
        for (int i = 0; i < m; i++) {
            B[i] = rand.nextInt(100);
        }

        System.out.println("\nПочатковий масив A: " + Arrays.toString(A));
        System.out.println("Початковий масив B: " + Arrays.toString(B));

        //  бульбашка
        bubbleSort(A);
        bubbleSort(B);

        System.out.println("\nВідсортований A: " + Arrays.toString(A));
        System.out.println("Відсортований B: " + Arrays.toString(B));

        //  третій відсортований масив
        int[] C = mergeArrays(A, B);

        System.out.println("\nЗлитий відсортований масив C: " + Arrays.toString(C));
    }

    // сортування бульбашк
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    //  злиття 2х відсорт масив
    public static int[] mergeArrays(int[] A, int[] B) {
        int n = A.length;
        int m = B.length;
        int[] C = new int[n + m];

        int i = 0, j = 0, k = 0;

        // злиття 2х масив у відсорт порядку
        while (i < n && j < m) {
            if (A[i] <= B[j]) {
                C[k++] = A[i++];
            } else {
                C[k++] = B[j++];
            }
        }

        
        while (i < n) C[k++] = A[i++];
        while (j < m) C[k++] = B[j++];

        return C;
    }
}
