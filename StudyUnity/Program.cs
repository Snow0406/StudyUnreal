using System;

namespace Snow
{
    class StudentInfo
    {
        public int age;
        public string name;
    }
    class Program
    {
        static Dictionary<string, StudentInfo> studentInfos = new Dictionary<string, StudentInfo>();
        static void Main()
        {
            bool isPlay = true;
            while (isPlay) {

                Console.WriteLine("1.입력, 2.편집, 3.삭제, 4.출력, 0.나가기");

                string input = Console.ReadLine();
                switch (input) {
                    case "1":
                        SetStudentInfo();
                        break;
                    case "2":
                        EditStudentInfo();
                        break;
                    case "3":
                        DeleteStudentInfo();
                        break;
                    case "4":
                        PrintStudentInfo();
                        break;
                    case "0":
                        isPlay = false;
                        break;
                }
            }
            Console.WriteLine(studentInfos.Count);

        }

        static void SetStudentInfo()
        {
            StudentInfo student = new StudentInfo();
            Console.WriteLine("학생의 나이를 입력하세요.");
            string input = Console.ReadLine();
            int age = int.Parse(input);
            student.age = age;
            Console.WriteLine("학생의 이름을 입력하세요.");
            input = Console.ReadLine();
            student.name = input;
            studentInfos.Add(student.name, student);
        }
        static void EditStudentInfo()
        {
            Console.WriteLine("수정 원하는 학생 이름 입력하세요");
            PrintStudentInfo();
            string input = Console.ReadLine();
            if(studentInfos.ContainsKey(input)) {
                Console.WriteLine("새로운 나이를 입력");
                int age = int.Parse(Console.ReadLine());
                studentInfos[input].age = age;
            } else {
                Console.WriteLine("학생의 이름이 없습니다");
            }
        }
        static void DeleteStudentInfo()
        {
            Console.WriteLine("삭제 원하는 학생 이름 입력하세요");
            PrintStudentInfo();
            string input = Console.ReadLine();
            if (studentInfos.ContainsKey(input)) {
                studentInfos.Remove(input);
                Console.WriteLine("삭제 완료");
            }
        }
        static void PrintStudentInfo()
        {
            foreach (var student in studentInfos) {
                Console.WriteLine($"name : {student.Value.name}, age : {student.Value.age}");
            }
        }
    }
}