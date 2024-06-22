using System;
using System.Reflection;
using System.Diagnostics;

namespace test
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Assembly assembly = Assembly.GetExecutingAssembly();
            FileVersionInfo fileVersionInfo = FileVersionInfo.GetVersionInfo(assembly.Location);
            string version = fileVersionInfo.ProductVersion;
            Console.WriteLine("Hello World! From C# {0}! ", version);
        }
    }
}
