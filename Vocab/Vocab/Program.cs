using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vocab
{
    class Program
    {
        static void Main(string[] args)
        {
            var vocab_list = new List<vocab>();
            string answer = "";
            while (answer != "e")
            {
                Console.WriteLine("What you want to do? 1 - Do a Test, 2 - add vocab, 3 - print all, e - exit");
                answer = Console.ReadLine();

                switch (answer)
                {
                    case "1":
                        test_vocab_list(vocab_list);
                        break;
                    case "2":
                        add_word(vocab_list);
                        break;
                    case "3":
                        print_vocab_list(vocab_list);
                        break;
                    default:
                        Console.WriteLine("Wrong Input");
                        break;
                }
            }

            Console.WriteLine("Bye");
        }


        static void add_word(List<vocab> vocab_list)
        {
            string german;
            string english;
            Console.Write("German: ");
            german = Console.ReadLine();
            Console.Write("English: ");
            english = Console.ReadLine();
            vocab_list.Add(new vocab(english, german));
        }

        static void print_vocab_list(List<vocab> vocab_list)
        {
            foreach (vocab voc in vocab_list)
                Console.WriteLine(voc.ToString());
        }

        static void test_vocab_list(List<vocab> vocab_list)
        {
            var rnd = new Random();
            var result = vocab_list.OrderBy(item => rnd.Next()).ToList();
            string answer;
            for (int i = 0; i < 10 && i < result.Count; i++)
            {
                Console.WriteLine("Whats " + result[i].English + " in German? ");
                answer = Console.ReadLine();
                if (result[i].compareGerman(answer))
                    Console.WriteLine("Right");
                else
                    Console.WriteLine("Wrong it is " + result[i].German);
            }
        }

    }
}
