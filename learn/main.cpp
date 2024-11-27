using System;

public class Program
{
    public static void Main(string[] args)
    {
        // Задача 1
        Console.WriteLine("Введите строку:");
        string str = Console.ReadLine();
        Console.WriteLine("Введите символ:");
        char symbol = Console.ReadKey().KeyChar;
        Console.WriteLine();
        int count = 0;
        foreach (char c in str)
        {
            if (c == symbol)
            {
                count++;
            }
        }
        double percentage = (double)count / str.Length  100;
        Console.WriteLine($"Процент вхождения символа '{symbol}' в строку: {percentage:F2}%");

        // Задача 2
        double[,] arr = new double[10, 10];
        Random random = new Random();
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                arr[i, j] = random.NextDouble()  100;
            }
        }
        double[] rowSums = new double[10];
        double[] colProducts = new double[10];
        double maxDiagonal = double.MinValue;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                rowSums[i] += arr[i, j];
                colProducts[j] = arr[i, j];
                if (i == j && arr[i, j] > maxDiagonal)
                {
                    maxDiagonal = arr[i, j];
                }
            }
        }
        Console.WriteLine("Суммы элементов строк:");
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine($"Строка {i + 1}: {rowSums[i]}");
        }
        Console.WriteLine("Произведения элементов столбцов:");
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine($"Столбец {i + 1}: {colProducts[i]}");
        }
        Console.WriteLine($"Максимальный элемент главной диагонали: {maxDiagonal}");
        
    }
}

// Задача 3
public static bool IsPalindrome(string text)
{
    text = text.ToLower().Replace(" ", "");
    int left = 0;
    int right = text.Length - 1;
    while (left < right)
    {
        if (text[left] != text[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Задача 4
public static int[,] SumMatrices(int[,] matrix1, int[,] matrix2)
{
    if (matrix1.GetLength(0) != matrix2.GetLength(0) || matrix1.GetLength(1) != matrix2.GetLength(1))
    {
        throw new ArgumentException("Матрицы должны иметь одинаковые размеры");
    }
    int rows = matrix1.GetLength(0);
    int cols = matrix1.GetLength(1);
    int[,] result = new int[rows, cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i, j] = matrix1[i, j] + matrix2[i, j];
        }
    }
    return result;
}

public static int[,] MultiplyMatrices(int[,] matrix1, int[,] matrix2)
{
    if (matrix1.GetLength(1) != matrix2.GetLength(0))
    {
        throw new ArgumentException("Количество столбцов первой матрицы должно быть равно количеству строк второй матрицы");
    }
    int rows1 = matrix1.GetLength(0);
    int cols1 = matrix1.GetLength(1);
    int cols2 = matrix2.GetLength(1);
    int[,] result = new int[rows1, cols2];
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                result[i, j] += matrix1[i, k]  matrix2[k, j];
            }
        }
    }
    return result;
}

// Задача 5
public static double CalculateSequenceSum()
{
    double sum = 1;
    double currentTerm = 1;
    while (currentTerm > 0.000001)
    {
        currentTerm /= 3;
        sum += currentTerm;
    }
    return sum;
}