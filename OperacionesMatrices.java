import java.util.Scanner;

//Programa de operaciones con matrices 2x3 Hace suma, resta y multiplicación de dos matrices

public class OperacionesMatrices {
    
    public static void main(String[] args) {
        // Aquí empiezo todo el programa
        Scanner sc = new Scanner(System.in);
        int[][] matrizA = new int[2][3];  // Mi primera matriz
        int[][] matrizB = new int[2][3];  // Mi segunda matriz

        // Primero pido los números al usuario
        System.out.println("=== Vamos a llenar las matrices ===");
        CompletarMatrices(matrizA, matrizB, sc);

        // Ahora calculo todo
        System.out.println("\n=== Haciendo los cálculos ===");
        int[][] suma = sumaMatriz(matrizA, matrizB);
        int[][] resta = restaMatriz(matrizA, matrizB);
        int[][] multi = multiMatriz(matrizA, matrizB);

        // Y muestro los resultados bonitos
        System.out.println("\n=== Aquí están los resultados ===");
        mostrarResultado("Matriz A:", matrizA);
        mostrarResultado("Matriz B:", matrizB);
        mostrarResultado("Suma:", suma);
        mostrarResultado("Resta:", resta);
        mostrarResultado("Multiplicación:", multi);

        sc.close();  // Cierro el scanner 
        System.out.println("¡Listo! Programa terminado.");
    }

    //Método para que el usuario meta los números
    public static void CompletarMatrices(int[][] m1, int[][] m2, Scanner sc) {
        //M2
        System.out.println("Ingresa los valores de la Matriz 1 (2x3):");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("M1[" + i + "][" + j + "] = ");
                m1[i][j] = sc.nextInt();  // Guardo el número en esa posición
            }
            System.out.println();  // Salto de línea para que se vea ordenado
        }

        //M2
        System.out.println("Ingresa los valores de la Matriz 2 (2x3):");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("M2[" + i + "][" + j + "] = ");
                m2[i][j] = sc.nextInt();
            }
            System.out.println();
        }
    }

    // Suma
    public static int[][] sumaMatriz(int[][] a, int[][] b) {
        int[][] resultado = new int[2][3];  // Creo una matriz nueva vacía
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                resultado[i][j] = a[i][j] + b[i][j];  // Sumo posición por posición
            }
        }
        return resultado;  // Devuelvo la matriz con las sumas
    }

    // Resta
    public static int[][] restaMatriz(int[][] a, int[][] b) {
        int[][] resultado = new int[2][3];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                resultado[i][j] = a[i][j] - b[i][j];  // Resto posición por posición
            }
        }
        return resultado;
    }

    // Multiplicación
    public static int[][] multiMatriz(int[][] a, int[][] b) {
        int[][] resultado = new int[2][3];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                resultado[i][j] = a[i][j] * b[i][j];  // Multiplico posición por posición
            }
        }
        return resultado;
    }

    //Imprime las matrices como tabla
    public static void mostrarResultado(String titulo, int[][] matriz) {
        System.out.println("\n" + titulo);
        for (int i = 0; i < matriz.length; i++) {  // Recorre las filas
            for (int j = 0; j < matriz[0].length; j++) {  // Recorre las columnas
                System.out.print(matriz[i][j] + "\t");  // Imprimo número + espacio
            }
            System.out.println();  // Salto de línea 
        }
        System.out.println();  // Espacio entre matrices
    }
}
