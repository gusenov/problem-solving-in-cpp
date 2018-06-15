#include <iostream>
// #include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;

struct student {
    char familya[80], name[80], otch[80], group[80];
    int year;
};
struct queue {
    student x;
    queue* next;
};

void print(const student& x);
queue* push(queue* end, student x);
queue* pop(queue* beg, student& x);
queue* at(queue* beg, int pos);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    queue *beg = 0, *end = 0;
    int menu;
    cout<<"Input number:\n";
    cout<<"1.Read file\n";
    cout<<"2.Write file\n";
    cout<<"3.Add student\n";
    cout<<"4.Pop student\n";
    cout<<"5.Print queue\n";
    cout<<"6.Print number\n";
    cout<<"7.Search student\n";
    cout<<"8.Delete queue\n";
    cout<<"9.Close program\n";
    do {
        cout<<"-number: ";
        cin>>menu;
        switch (menu) {
        case 1: {
            char file_name[80];
            cout<<"Input file name: ";
            cin>>file_name;
            FILE* file = fopen(file_name, "r");
            if (file == NULL) {
                cout<<"There is no file with name "<<file_name<<"\n";
                break;
            }
            student temp;
            while (fscanf(file, "%s%s%s%s%i", temp.familya, temp.name, temp.otch, temp.group, &temp.year) != EOF) {
                if (!beg)
                    beg = end = push(end, temp);
                else
                    end = push(end, temp);
            }
            fclose(file);
            cout<<"done\n";
            break;
        }

        case 2: {
            if (!beg) {
                cout<<"queue is empty\n";
                break;
            }
            char file_name[80];
            cout<<"Input file name: ";
            cin>>file_name;
            FILE* file = fopen(file_name, "w");
            queue* p = beg;
            while (p) {
                fprintf(file, "%s \t%s \t%s \t%s \t%i\n", p->x.familya, p->x.name, p->x.otch, p->x.group, p->x.year);
                p = p->next;
            }
            fclose(file);
            cout<<"done\n";
            break;
        }
        case 3: {
            cout<<"Input student:\n";
            student temp;
            cin>>temp.familya>>temp.name>>temp.otch>>temp.group>>temp.year;
            if (!beg)
                beg = end = push(end, temp);
            else
                end = push(end, temp);
            cout<<"done\n";
            break;
        }
        case 4: {
            if (!beg) {
                cout<<"queue is empty\n";
                break;
            }
            student temp;
            beg = pop(beg, temp);
            print(temp);
            cout<<"done\n";
            break;
        }
        case 5: {
            if (!beg) {
                cout<<"queue is empty\n";
                break;
            }
            queue* p = beg;
            int i = 1;
            while (p) {
                cout<<i<<" ";
                print(p->x);
                p = p->next;
                i++;
            }
            break;
        }
        case 6: {
            if (!beg) {
                cout<<"queue is empty\n";
                break;
            }
            queue* temp;
            int pos;
            cout<<"Enter number: ";
            cin>>pos;
            temp = at(beg, pos);
            if (temp) {
                print(temp->x);
                cout<<"done\n";
            }
            else
                cout<<"non-existent number\n";
            break;
        }
        case 7: {
            if (!beg) {
                cout<<"queue is empty\n";
                break;
            }
            char input[80];
            cout<<"Input student for search: ";
            cin>>input;
            queue* p = beg;
            int i = 1;
            bool result = 0;
            while (p) {
                if (strcmp(p->x.familya, input) == 0) {
                    cout<<i <<" ";
                    print(p->x);
                    result = 1;
                }
                p = p->next;
                i++;
            }
            if (!result)
                cout<<"No results for "<<input<<"\n";
            break;
        }
        case 8:
        case 9: {
            student temp;
            while (beg)
                beg = pop(beg, temp);
            cout<<"done\n";
            break;
        }
        default:
            cout<<"wrong number\n";
        }
    } while (menu != 9);
    return 0;
}
void print(const student& x)
{
    cout<<x.familya<<" \t"<<x.name<<" \t"<<x.otch<<" \t"<<x.group<<"\t"<<x.year<<"\n";
}
queue* push(queue* end, student x)
{
    queue* p = new queue;
    p->x = x;
    p->next = 0;
    if (end)
        end->next = p;
    return p;
}
queue* pop(queue* beg, student& x)
{
    x = beg->x;
    queue* p = beg->next;
    delete beg;
    return p;
}
queue* at(queue* beg, int pos)
{
    queue* p = beg;
    int i = 1;
    while (i < pos && p->next) {
        p = p->next;
        i++;
    }
    if (i == pos)
        return p;
    else
        return 0;
}
