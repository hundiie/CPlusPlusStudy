//using System;

//namespace Delegate
//{
//    delegate int MyDelegate(int a, int b);//대리자 선언

//    //테스트 함수 제작
//    class Calculator
//    {
//        public int PLUS(int a, int b)
//        {
//            return a + b;
//        }
//        public int MINUS(int a, int b)
//        {
//            return a - b;
//        }
//    }

//    //콜백 사용
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            Calculator _calculator = new Calculator();
//            MyDelegate Callback;

//            Callback = new MyDelegate(_calculator.PLUS);
//            Console.WriteLine(Callback(7, 2));

//            Callback = new MyDelegate(_calculator.MINUS);
//            Console.WriteLine(Callback(7, 2));

//        }
//    }
//}

//using System;

//namespace usingCallback
//{
//    //대리자 생성
//    delegate int Compare<T>(T a, T b);

//    class MainApp
//    {
//        //대리자가 참조할 비교 메서드 작성
//        static int AscendCompare<T>(T a, T b) where T : IComparable<T>
//        {
//            return a.CompareTo(b); //자신보다 크면 -1 같으면 0 작으면 1 을 반환합니다.
//        }

//        static int DescendCompare<T>(T a, T b) where T : IComparable<T>
//        {
//            return a.CompareTo(b) * -1; //* -1을 하면서 자신보다 크면 1 같으면 0 작으면 -1 을 반환합니다.
//        }
//        //정렬 메소드를 작성
//        static void BubbleSort<T>(T[] DataSet, Compare<T> Comparer)
//        {
//            int i = 0;
//            int j = 0;
//            T temp;

//            for (i = 0; i < DataSet.Length - 1; i++)
//            {
//                for (j = 0; j < DataSet.Length - (i + 1); j++)
//                {
//                    if (Comparer(DataSet[j], DataSet[j + 1]) > 0)
//                    {
//                        temp = DataSet[j + 1];
//                        DataSet[j + 1] = DataSet[j];
//                        DataSet[j] = temp;
//                    }
//                }
//            }
//        }

//        static void Main(string[] args)
//        {
//            //정렬 메소드 호출
//            int[] array = { 3, 7, 4, 2, 10 };

//            Console.WriteLine("Sorting...");
//            BubbleSort<int>(array,new Compare<int>(AscendCompare));
//            // 결과 2 3 4 7 10
//            for (int i = 0; i < array.Length; i++)
//            {
//                Console.Write($"{array[i]} ");
//            }
//            Console.WriteLine();

//            string[] array2 = { "asd", "sdf", "dfg", "fgh" };

//            Console.WriteLine("Sorting...");
//            BubbleSort<string>(array2, new Compare<string>(DescendCompare));

//            for (int i = 0; i < array.Length; i++)
//            {
//                Console.Write($"{array2[i]} ");
//            }

//            Console.WriteLine();
//        }
//    }
//}

using System;

using System;

namespace EventTest
{
    delegate void EventHandler(string message);

    class Mynotifier
    {
        //대리자 선언
        public event EventHandler SomethingHappened;
        public void DoSomething(int number)
        {
            int temp = number % 10;

            if (temp != 0 && temp % 3 == 0)
            {
                SomethingHappened(String.Format($"{number} : 짝"));
            }
        }
    }

    class MainApp
    {
        static public void Myhandler(string message)
        {
            Console.WriteLine(message);
        }

        static void Main(string[] args)
        {
            Mynotifier notifier = new Mynotifier();
            notifier.SomethingHappened += new EventHandler(Myhandler);

            for (int i = 0; i < 30; ++i)
            {
                notifier.DoSomething(i);
            }
        }
    }
}  