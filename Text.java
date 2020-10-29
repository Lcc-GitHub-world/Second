package Student;


import Book.Book;

import java.util.Scanner;

class Student {
    String name;
    int age;
    String major;
    String ID;

    public Student(String name, int age, String major, String ID) {
        this.name = name;
        this.age = age;
        this.major = major;
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getMajor() {
        return major;
    }

    public String getID() {
        return ID;
    }

    public void setStudents(String name, int age, String major, String ID){
        this.name = name;
        this.age = age;
        this.major = major;
        this.ID = ID;
    }

    public void printInfo() {
        System.out.println(name + "\t" + age + "\t" + major + "\t" + ID);
    }

}

class Manage {
    public static final int SIZE = 100; //图书库最大藏书量
    Student[] students; //学生库
    int count;        //当前学生库人数
    Scanner scan;

    public Manage() {
        students = new Student[SIZE];
        //初始化图书库，默认里面有5本书，信息如下
        students[0] = new Student("张三", 18, "英语", "0001");
        students[1] = new Student("李四", 19, "计算机", "0002");
        students[2] = new Student("王五", 18, "电子信息", "0003");


        count = 3;
        scan = new Scanner(System.in);
    }

    //执行循环
    public void run() {

        int userChoice = 0;
        //循环处理，直到用户选择了“0...退出”
        do {
            displayMenu();

            //读取用户输入
            userChoice = scan.nextInt();

            switch (userChoice) {
                case 0:
                    System.out.println("成功退出系统，欢迎再次使用！");
                    break;
                case 1:
                    printStudent();
                    break;
                case 2:
                    addStudent();
                    break;
                case 3:
                    deleteStudent();
                    break;
                case 4:
                    modifyStudent();
                    break;
                case 5:
                    findStudent();
                    break;
                default:
                    System.out.println("输入非法,请重新输入！");

            }
        } while (userChoice != 0);
        scan.close();
    }

    //打印菜单
    void displayMenu() {
        System.out.println("---------------------");
        System.out.println("    学生管理系统     ");
        System.out.println("---------------------");
        System.out.println("|   0...退出系统	|");
        System.out.println("|   1...显示学生	|");
        System.out.println("|   2...增加学生	|");
        System.out.println("|   3...删除学生	|");
        System.out.println("|   4...修改学生	|");
        System.out.println("|   5...查询学生	|");
        System.out.println("---------------------");
        System.out.print("请输入选项：");
    }

    //显示学生
    void printStudent() {
        System.out.println("------------------------------------------");
        System.out.println("姓名\t年龄\t专业\t学号");
        System.out.println("------------------------------------------");
        for (int i = 0; i < count; i++) {
            System.out.println((i + 1) + "\t" + students[i].getName() + "\t" + students[i].getAge() + "\t" + students[i].getMajor() + "\t" + students[i].getID());
        }
        System.out.println("-------------------------------------------");
    }

    //增加学生
    void addStudent() {
        if (count < SIZE) {
            System.out.println("-------------------------------------------");

            System.out.print("请输入姓名：");
            String name = scan.nextLine();
            System.out.print("请输入年龄：");
            int age = scan.nextInt();
            System.out.print("请输入专业：");
            String major = scan.nextLine();
            System.out.println("请输入学号");
            String ID = scan.nextLine();
            Student student = new Student(name, age, major, ID);
            students[count] = student;
            count++;
            System.out.println("成功增加1名学生！当前学生信息如下：");
            printStudent();
        } else {
            System.out.println("学生库已满！");
        }
    }

    //删除学生
    void deleteStudent() {
        int id = -1;
        while (true) {
            printStudent();
            System.out.print("请输入序号删除学生，输入-1返回主菜单: ");
            int userChoice = scan.nextInt();
            if (userChoice == -1) {
                break;
            } else {
                id = findByOrder(userChoice);
                if (id > -1) {
                    for (int j = id; j < count - 1; j++) {  //用for循环的形式实现对数组的删除
                        students[j] = students[j + 1];
                    }
                    count--;
                    System.out.println("删除成功！");
                } else
                    System.out.println("输入错误！请重新输入！");
            }
        }
    }

    //修改学生
    void modifyStudent() {   //修改图书

        while(true)	{
            printStudent();

            System.out.print("请输入序号修改学生信息，输入-1返回主菜单: ");
            int userChoice = scan.nextInt();
            int id = -1;
            if(userChoice == 0){
                break;
            }
            else {
                id = findByOrder(userChoice);
                if(modifyStudentId(id) == true) {
                    System.out.println("修改成功！当前学生信息如下：");
                    students[id].printInfo();;
                }
                else
                    System.out.println("输入错误！请重新输入！");
            }
        }
    }

    //查询学生
    void findStudent() {
        while(true){
            System.out.println("----------------------------------------------");
            System.out.println("请输入按哪种方法查找图书：0、返回主菜单    1、姓名   2、学号  ");
            int userChoice = scan.nextInt();
            if(userChoice == 0)	{
                break;
            }
            else if(userChoice >= 3) {
                System.out.println("输入错误,请重新输入！");
            }
            else {
                if(userChoice == 1) {
                    System.out.println("请输入您要查找的学生姓名：");
                    String name = scan.next();
                    findByName(name);

                }
                else if(userChoice == 2) {
                    System.out.println("请输入您要查找的学号：");
                    String ID = scan.next();
                    findByID(ID);
                }
            }
        }
    }

    //按序号(1~count)返回数组下标id
    int findByOrder(int number) {

        if (number > 0 && number <= count) {

            return number - 1;
        } else
            return -1;
    }

    //按姓名查找学生，返回id
    void findByName(String name) {
        int x = 0;
        for (int i = 0; i < count; i++) {
            String keyword = name;
            if (students[i].getName().contains(keyword)) { //返回true
                students[i].printInfo();
            } else {
                x++;
            }
        }
        if (x == count) {
            System.out.println("查找失败！");
        }
        x = 0;
        //************End*************
    }

    //修改学生过程
    boolean modifyStudentId(int id) {
        if(id > -1 && id < count)	{
            System.out.println("图书信息如下：");
            students[id].printInfo();
            String nameOld = students[id].getName();
            int ageOld = students[id].getAge();
            String majorOld = students[id].getMajor();
            String IDOld = students[id].getID();
            scan.nextLine();  //释放前一个回车

            System.out.print("请输入姓名(直接回车保持不变)：");
            String name = scan.nextLine();
            name = name.isEmpty() ? nameOld : name;
            System.out.print("请输入年龄(直接回车保持不变)：");
            String strAge = scan.nextLine();
            int age = strAge.isEmpty()? ageOld : Integer.valueOf(strAge).intValue();
            System.out.print("请输入专业(直接回车保持不变)：");
            String major = scan.nextLine();
            major = major.isEmpty() ? majorOld : major;
            System.out.print("请输入ID(直接回车保持不变)：");
            String ID = scan.nextLine();
            ID = ID.isEmpty() ? IDOld : ID;

            students[id].setStudents(name, age, major, ID);

            return true;
        }
        else {

            return false;
        }
    }

    //按学号查找学生，返回id
    void findByID(String ID) {
        int x = 0;
        for(int i = 0; i < count; i++){
            String keyword = ID;
            if(students[i].getID().equals(keyword)){ //返回true
                students[i].printInfo();
            }
            else{
                x++;
            }


        }
        if(x == count){
            System.out.println("查找失败！");
        }
        x = 0;

        //************End*************
    }

}
public class Text {

    public static void main(String[] args) {
        Manage studentManage = new Manage();
        studentManage.run();
    }
}
