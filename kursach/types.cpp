#include <iostream>
#include <cmath>
#include "types.h"
#include <windows.h>
#include <iomanip>
#include <string>


using namespace std;

void type1::Get_answer() {
    cout << "������� �������� ����� �������� �" << endl;
}
void type1::show() {
    cout << "��������� 0 = 0" << endl;
}



type2::type2(double a1) {
    A = a1;
}
void type2::Get_answer() {
    cout << "������� �������� � = 0" << endl;
}
void type2::show() {
    cout << "��������� " << A << "*x^2 = 0" << endl;
}



type3::type3(double c1) {
    C = c1;
}
void type3::Get_answer() {
    if (C != 0) { cout << "������ ���" << endl; }
    else { cout << "������� �������� ����� �������� �" << endl; }
}
void type3::show() {
    cout << C << " = 0" << endl;
}



type4::type4(double a1, double c1) {
    A = a1;
    C = c1;
}
void type4::Get_answer() {
    double k = ((-1) * C) / A;
    if (k >= 0) {
        double x1 = sqrt(k);
        double x2 = sqrt(k) * (-1);
        cout << "����� ���������: " << endl << "X1 = " << x1 << endl << "X2 = " << x2 << endl;
    }
    else {
        cout << "������ ���" << endl;
    }
}
void type4::show() {
    cout << "��������� " << A << "*x^2 + " << C << " = 0" << endl;
}
void type4::Get_answer_podbor() {
    if ((((-1) * C) / A) < 0) {
        cout << "������ ������� ������� ���" << endl;
    }
    else {
        double min = abs(0 - A * (-20) * (-20) - C);
        double x = -20;
        for (double i = -20; i < 20.01; i = i + 0.01) {
            double temp = abs(0 - A * (i) * (i)-C);
            if (temp < min) {
                min = temp;
                x = i;
            }
        }
        cout << "�����������, ���� �� ������ ���������: " << x << endl;
    }
}



type5::type5(double b1, double c1) {
    B = b1;
    C = c1;
}
void type5::Get_answer() {
    cout << "������ ���������: " << (-1) * (C / B) << endl;
}
void type5::show() {
    cout << "��������� " << B << "*x + " << C << " = 0" << endl;
}
void type5::Get_answer_podbor() {
    double min = abs(0 - B * (-20) - C);
    double x = -20;
    for (double i = -20; i < 20.01; i = i + 0.01) {
        double temp = abs(0 - B * (i)-C);
        if (temp < min) {
            min = temp;
            x = i;
        }
    }
    cout << "�����������, ���� �� ������ ���������: " << x << endl;
}



type6::type6(double a1, double b1, double c1) {
    A = a1;
    B = b1;
    C = c1;
}
void type6::Get_answer() {
    double D = B * B - 4 * A * C;
    if (D < 0) {
        cout << "��������� �� ����� �������������� ������" << endl;
    }
    else {
        if (D == 0) {
            double x = ((-1) * B - sqrt(D)) / (2 * A);
            cout << "������ ���������: " << x << endl;
        }
        else {
            double x1 = ((-1) * B - sqrt(D)) / (2 * A);
            double x2 = ((-1) * B + sqrt(D)) / (2 * A);
            cout << "����� ���������: " << endl;
            cout << "X1 = " << x1 << endl << "X2 = " << x2 << endl;
        }
    }
}
void type6::show() {
    cout << "��������� " << A << "*x^2 + " << B << "*x + " << C << " = 0" << endl;
}
void type6::Get_answer_podbor() {
    double D = B * B - 4 * A * C;
    if (D < 0) {
        cout << "��������� �� ����� �������������� ������" << endl;
    }
    else {
        double min = abs(0 - A * (-20) * (-20) - B * (-20) - C);
        double x = -20;
        for (double i = -20; i < 20.01; i = i + 0.01) {
            double temp = abs(0 - A * (i) * (i)-B * i - C);
            if (temp < min) {
                min = temp;
                x = i;
            }
        }
        cout << "�����������, ���� �� ������ ���������: " << x << endl;
    }
}



type7::type7(double b1) {
    B = b1;
}
void type7::Get_answer() {
    cout << "������ ���������: x = 0" << endl;
}
void type7::show() {
    cout << "��������� " << B << "*x = 0" << endl;
}



type8::type8(double a1, double b1) {
    A = a1;
    B = b1;
}
void type8::Get_answer() {
    double x = ((-1) * B) / A;
    cout << "����� ���������: " << endl;
    cout << "X1 = 0" << endl << "X2 = " << x << endl;
}
void type8::show() {
    cout << "��������� " << A << "*x^2 + " << B << "*x = 0 " << endl;
}
void type8::Get_answer_podbor() {
    double min = abs(0 - A * (-20) * (-20) - B * (-20));
    double x = -20;
    for (double i = -20; i < 20.01; i = i + 0.01) {
        if (i != 0) {
            double temp = abs(0 - A * i * i - B * (i));
            if (temp < min) {
                min = temp;
                x = i;
            }
        }
    }
    cout << "�����������, ���� �� ������ ���������: " << x << endl;
}


void inter::setConsoleWindowSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    COORD size = { width, height };
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    SetConsoleScreenBufferSize(hConsole, size);
};




void inter::centerTextWithFrame(const string& text)
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN); // �������� ������ ������
    int frameWidth = 120; // ������ �����

    int paddingWidth = (frameWidth - text.length()) / 2;

    // ����� �����

    HANDLE aConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    
    for (int i = 0; i < frameWidth; ++i)
    {
        cout << "-";
    }

    

    cout << endl;

    // ����� ������ � ������������� �� ������ � �������� �����
    HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    cout << setw(paddingWidth) << "" << text << endl;

    HANDLE YConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // ����� �����
    for (int i = 0; i < frameWidth; ++i)
    {
        cout << "-";
    }

   

    cout << endl;
}




void inter::waitForExit()
{
    std::cin.ignore();
}


void inter::setConsoleFontSize(int fontSize)
{
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
    fontInfo.dwFontSize.Y += fontSize; // ����������� ������ ������ �� �������� ��������
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
}






// ������� ��� ��������� ����� ������ ����������
void inter::setColor(std::string text, std::string color) {
    // ��������� ����� ���������� � ������� ���������� ������
    std::string coloredText = color + text + "\033[0m";

    // ������� ���������� �����
    std::cout << coloredText << std::endl;
}






string inter::Level1() {
    string output;

    double A, B, C;

    while (true) {
        HANDLE WConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        string s1 = "�������� ��������:";
        string s2 = "1. ������� ��� ���������";
        string s3 = "2. ����� �� ����������";
        string s4 = "�����: ";
        centerTextWithFrame(s1);
        centerTextWithFrame(s2);
        centerTextWithFrame(s3);
        cout << endl;
        cout << s4 << endl;


        std::string strchoice;
        int choice;

        std::cin >> strchoice;


        try {
            choice = std::stoi(strchoice);
            std::cout << "�� ����� �����: " << choice << std::endl;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            string er1 = "������:�������� ������";

            centerTextWithFrame(er1);

            Level3();  // ����� �� ��������� ��� ���������� ������ �������� � ������ ������
        }
        catch (const std::out_of_range& e) {

            system("cls");
            string er2 = "������: ����� ������� �� ������� ��������� ���� int.";
            centerTextWithFrame(er2);

            Level3();
        }


        if (choice == 1) {
            system("cls");
            Level2();

        }


        else if (choice == 2) {
            waitForExit();
            cout << "" << endl;
            system("cls");

            setConsoleFontSize(17);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            std::cout << "A problem has been detected and windows has been shut down to prevent damage to your computer If this the first time you ve seen this stop error screen, restart your computer. If this screen appears again, follow these steps Check to be sure you have adequate disk space. If a driver is identified in the stop message, disable the driver or check with the manufacturer for driver updates. Try changing video adapters Check with your hardware vendor for any bios updates. Disable bios memory options such as caching or shadowing If you need tu use Safe mode to remove or dicable components, restart your computer, press f8 to select Advanced Startup Options, and then select Safe mode  Stop 0x0000001e (0xffffffffc0000005,0xfffff80001098A60  Beginning dump of physical memory physical memory dump complete Contact your system administrator or technical support group for further assistance �������: ���������� > ������� �������� ���� ���������� � ���� ���� �������, ����� ������������� ����������� ���������� ���� ��� ������ ���, ����� �� ������ ��� ��������� ������ ������, ������������� ���������. ���� ���� ����� ���������� �����, ��������� ��������� �������� ���������, ����� � ��� ���� ����������� ������������ �����. ���� ������� ������ � ����-������, ��������� ������� ��� ��������� � �������������� ��� ���������� ���������. ���������� �������� ������������� ���������� � ���������� ������������ ��� ����� ���������� BIOS. ��������� BIOS ������ ��������, ����� ��� ����������� ��� ��������� ���� ��� ���������� ������������ �� ���������� ������, ����� ������� ��� dicable ����������, ������������� ���������, ������� F8 ����� ������� ����������� ��������� �������, � ����� �������� ���������� �����  STOP 0x0000001E (0xffffffffc0000005, 0xfffff80001098A60  ������ ���� ���������� ������ ���������� ������ ���� ������ ���������� � ������ ���������� �������������� ��� � ������ ����������� ��������� ��� ��������� �������������� ������                                                               " << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "        �����!                                                       " << std::endl;

           
            waitForExit();
            break;
        }
        else {


            system("cls");

            string s1 = "������ ������, ���� ��������������";
            centerTextWithFrame(s1);

            Level1();
            //throw std::runtime_error("�������� �����"); // ������� ����������
        }

    }
    return output;
};

string inter::Level2() {
    string output;
    // ������ ������ 2

    while (true) {


        HANDLE WConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        string s1 = "1. ��������� ����: 0 = 0 ";
        string s2 = "2. ��������� ����: A*x^2 = 0 ";
        string s3 = "3. ��������� ����: C = 0 ";
        string s4 = "4. ��������� ����: A*x^2 + � = 0";
        string s5 = "5. ��������� ����: B*x + C = 0";
        string s6 = "6. ��������� ����: A*x^2 + B*x + C = 0";
        string s7 = "7. ��������� ����: B*x = 0";
        string s8 = "8. ��������� ����: A*x^2 + B*x = 0";
        centerTextWithFrame(s1);
        centerTextWithFrame(s2);
        centerTextWithFrame(s3);
        centerTextWithFrame(s4);
        centerTextWithFrame(s5);
        centerTextWithFrame(s6);
        centerTextWithFrame(s7);
        centerTextWithFrame(s8);


        string s0 = "0. �����";
        centerTextWithFrame(s0);

       
        std::cout << "�����: ";



        double A, B, C;

        std::string strchoice;
        int choice;

        std::cin >> strchoice;


        try {
            choice = std::stoi(strchoice);
            std::cout << "�� ����� �����: " << choice << std::endl;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            string er1 = "������: �������� ������";
            centerTextWithFrame(er1);

            Level3();  // ����� �� ��������� ��� ���������� ������ �������� � ������ ������
        }
        catch (const std::out_of_range& e) {

            system("cls");
            string er2 = "������: ����� ������� �� ������� ��������� ���� int.";
            centerTextWithFrame(er2);

            Level3();
        }



        if (choice == 1) {
            system("cls");
        Step1:
            cout << "������� ����������: " << endl;
            cin >> A;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step1;
            }
            type1 eq1;
            eq1.show();
            eq1.Get_answer();
            Level3();

        }
        else if (choice == 2) {
            system("cls");
        Step2:
            cout << "������� ����������: A " << endl;
            cin >> A;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step2;
            }
            type2 eq2(A);
            eq2.show();
            eq2.Get_answer();
            Level3();
        }
        else if (choice == 3) {
            system("cls");
        Step3:
            cout << "������� ����������: C" << endl;
            cin >> C;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step3;
            }
            type3 eq3(C);
            eq3.show();
            eq3.Get_answer();
            Level3();

        }
        else if (choice == 4) {
            system("cls");
        Step4:
            cout << "������� ����������: A � C " << endl;
            cin >> A >> C;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step4;
            }
            type4 eq4(A, C);
            eq4.show();
            eq4.Get_answer();
            eq4.Get_answer_podbor();
            Level3();

        }
        else if (choice == 5) {
            system("cls");
        Step5:
            cout << "������� ����������: B � C " << endl;
            cin >> B >> C;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step5;
            }
            type5 eq5(B, C);
            eq5.show();
            eq5.Get_answer();
            eq5.Get_answer_podbor();
            Level3();

        }
        else if (choice == 6) {
            system("cls");
        Step6:
            cout << "������� ����������: A, B � C " << endl;
            cin >> A >> B >> C;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step6;
            }
            type6 eq6(A, B, C);
            eq6.show();
            eq6.Get_answer();
            eq6.Get_answer_podbor();
            Level3();

        }
        else if (choice == 7) {
            system("cls");
        Step7:
            cout << "������� ����������: B " << endl;
            cin >> B;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step7;
            }
            type7 eq7(B);
            eq7.show();
            eq7.Get_answer();
            Level3();

        }
        else if (choice == 8) {
            system("cls");
        Step8:
            cout << "������� ����������: A � B " << endl;
            cin >> A >> B;
            if (cin.fail()) {
                cout << "������������ ������� ������. ���������� ��� ���." << endl;
                cin.clear();
                cin.ignore();
                goto Step8;
            }
            type8 eq8(A, B);
            eq8.show();
            eq8.Get_answer();
            eq8.Get_answer_podbor();
            Level3();

        }
        else if (choice == 0) {
            system("cls");

            Level1();
        }


        else {
            system("cls");


            string s8 = "������ ������, ���� ��������������";
            centerTextWithFrame(s8);

            Level2();
        }


    }


    return output;
};

string inter::Level3() {
    string output;
    while (true) {
        HANDLE WConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        string s1 = "�������� ��������:";
        string s2 = "1. ����������";
        string s3 = "2. ������� ����";
        string s4 = "3. ����� �� ����������";
        string s5 = "�����: ";
        centerTextWithFrame(s1);
        centerTextWithFrame(s2);
        centerTextWithFrame(s3);
        centerTextWithFrame(s4);
        cout << endl;
        cout << s5 << endl;


        std::string strchoice;
        int choice;

        std::cin >> strchoice;


        try {
            choice = std::stoi(strchoice);
            std::cout << "�� ����� �����: " << choice << std::endl;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            string er1 = "������: �������� ������";
            centerTextWithFrame(er1);

            Level3();  // ����� �� ��������� ��� ���������� ������ �������� � ������ ������
        }
        catch (const std::out_of_range& e) {

            system("cls");
            string er2 = "������: ����� ������� �� ������� ��������� ���� int.";
            centerTextWithFrame(er2);

            Level3();
        }



        if (choice == 1) {
            system("cls");
            Level2();

        }

        else if (choice == 2) {
            system("cls");
            Level1();

        }


        else if (choice == 3) {
            waitForExit();
            cout << "" << endl;
            system("cls");
            setConsoleFontSize(17);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            std::cout << "A problem has been detected and windows has been shut down to prevent damage to your computer If this the first time you ve seen this stop error screen, restart your computer. If this screen appears again, follow these steps Check to be sure you have adequate disk space. If a driver is identified in the stop message, disable the driver or check with the manufacturer for driver updates. Try changing video adapters Check with your hardware vendor for any bios updates. Disable bios memory options such as caching or shadowing If you need tu use Safe mode to remove or dicable components, restart your computer, press f8 to select Advanced Startup Options, and then select Safe mode  Stop 0x0000001e (0xffffffffc0000005,0xfffff80001098A60  Beginning dump of physical memory physical memory dump complete Contact your system administrator or technical support group for further assistance �������: ���������� > ������� �������� ���� ���������� � ���� ���� �������, ����� ������������� ����������� ���������� ���� ��� ������ ���, ����� �� ������ ��� ��������� ������ ������, ������������� ���������. ���� ���� ����� ���������� �����, ��������� ��������� �������� ���������, ����� � ��� ���� ����������� ������������ �����. ���� ������� ������ � ����-������, ��������� ������� ��� ��������� � �������������� ��� ���������� ���������. ���������� �������� ������������� ���������� � ���������� ������������ ��� ����� ���������� BIOS. ��������� BIOS ������ ��������, ����� ��� ����������� ��� ��������� ���� ��� ���������� ������������ �� ���������� ������, ����� ������� ��� dicable ����������, ������������� ���������, ������� F8 ����� ������� ����������� ��������� �������, � ����� �������� ���������� �����  STOP 0x0000001E (0xffffffffc0000005, 0xfffff80001098A60  ������ ���� ���������� ������ ���������� ������ ���� ������ ���������� � ������ ���������� �������������� ��� � ������ ����������� ��������� ��� ��������� �������������� ������    "                         << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "                                                               " << std::endl;
            std::cout << "        �����!                                                       " << std::endl;
            std::cout << "                                                               " << std::endl;

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            waitForExit();
            break;
        }
        else {
            system("cls");


            string s8 = "������ ������,���� ��������������";
            centerTextWithFrame(s8);

            Level3();
        }


    }
    return output;
};