// See https://aka.ms/new-console-template for more information

using System.Runtime.InteropServices;

class Sample
{
    public static void Main()
    {
        Console.WriteLine("\nHello World! From {0}\n", RuntimeInformation.FrameworkDescription);
    }
}