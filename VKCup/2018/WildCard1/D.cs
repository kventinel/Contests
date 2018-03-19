using System;
using System.Linq;

public static class Program
{
    public static void Main()
    {
        var str1 = Console.ReadLine().ToCharArray();
        var str2 = Console.ReadLine().ToCharArray();
        var str3 = Console.ReadLine().ToCharArray();
        var str4 = Console.ReadLine().ToCharArray();
        var str5 = Console.ReadLine().ToCharArray();
        var str6 = Console.ReadLine().ToCharArray();
        if (str1[3] == '.') {
            str1[3] = 'P';
        } else if (str1[4] == '.') {
            str1[4] = 'P';
        } else if (str2[3] == '.') {
            str2[3] = 'P';
        } else if (str2[4] == '.') {
            str2[4] = 'P';
        } else if (str1[0] == '.') {
            str1[0] = 'P';
        } else if (str1[1] == '.') {
            str1[1] = 'P';
        } else if (str1[6] == '.') {
            str1[6] = 'P';
        } else if (str1[7] == '.') {
            str1[7] = 'P';
        } else if (str2[0] == '.') {
            str2[0] = 'P';
        } else if (str2[1] == '.') {
            str2[1] = 'P';
        } else if (str2[6] == '.') {
            str2[6] = 'P';
        } else if (str2[7] == '.') {
            str2[7] = 'P';
        } else if (str3[3] == '.') {
            str3[3] = 'P';
        } else if (str3[4] == '.') {
            str3[4] = 'P';
        } else if (str4[4] == '.') {
            str4[4] = 'P';
        } else if (str4[3] == '.') {
            str4[3] = 'P';
        } else if (str3[0] == '.') {
            str3[0] = 'P';
        } else if (str3[1] == '.') {
            str3[1] = 'P';
        } else if (str3[6] == '.') {
            str3[6] = 'P';
        } else if (str3[7] == '.') {
            str3[7] = 'P';
        } else if (str4[0] == '.') {
            str4[0] = 'P';
        } else if (str4[1] == '.') {
            str4[1] = 'P';
        } else if (str4[6] == '.') {
            str4[6] = 'P';
        } else if (str4[7] == '.') {
            str4[7] = 'P';
        } else if (str5[3] == '.') {
            str5[3] = 'P';
        } else if (str5[4] == '.') {
            str5[4] = 'P';
        } else if (str6[3] == '.') {
            str6[3] = 'P';
        } else if (str6[4] == '.') {
            str6[4] = 'P';
        } else if (str5[0] == '.') {
            str5[0] = 'P';
        } else if (str5[1] == '.') {
            str5[1] = 'P';
        } else if (str5[6] == '.') {
            str5[6] = 'P';
        } else if (str5[7] == '.') {
            str5[7] = 'P';
        } else if (str6[0] == '.') {
            str6[0] = 'P';
        } else if (str6[1] == '.') {
            str6[1] = 'P';
        } else if (str6[6] == '.') {
            str6[6] = 'P';
        } else if (str6[7] == '.') {
            str6[7] = 'P';
        }
        Console.WriteLine(str1);
        Console.WriteLine(str2);
        Console.WriteLine(str3);
        Console.WriteLine(str4);
        Console.WriteLine(str5);
        Console.WriteLine(str6);
    }
}
