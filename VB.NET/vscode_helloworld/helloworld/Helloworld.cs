// See https://aka.ms/new-console-template for more information

using System.Diagnostics;
using System.Runtime.InteropServices;

namespace helloworld
{
    [DebuggerDisplay($"{{{nameof(GetDebuggerDisplay)}(),nq}}")]
    public class Helloworld
    {
        public static void Main()
        {
            Console.WriteLine("\nHello World! From {0}\n", RuntimeInformation.FrameworkDescription);
        }

        private string GetDebuggerDisplay()
        {
#pragma warning disable CS8603 // Possible null reference return.
            return ToString();
#pragma warning restore CS8603 // Possible null reference return.
        }
    }
}