
/* Created by tamarapple on 9/15/19 */



#include "tests.h"
#include "my_string.h"

void constructor_test() {
    MyString myString_1;
    MyString myString_2 = MyString();
    MyString myString_3 = MyString("Tamar");

    cout << myString_1 << endl;
    cout << myString_2 << endl;
    cout << myString_3 << endl;

}

void operetors_test() {
    try {
        MyString myString_1 = MyString("Tamar Appelboim");
        cout << myString_1 << endl;

        //********   operator[] **********//
        cout << "myString[0]: " << myString_1[0] << endl;

        cout << "myString[14]: " << myString_1[14] << endl;
        // invalid index
        // cout << "myString[-1]: " << myString[-1] << endl;
        // invalid index
        //cout << "myString[15]: " << myString_1[15] << endl;

        //********   operator= **********//

        MyString myString_2 = MyString("Tamar Appelboim");
        MyString myString_3 = MyString("Ayala Abm");
        MyString myString_4;

        cout << "myString_2: " << myString_2 << endl;
        cout << "myString_3: " << myString_3 << endl;
        cout << "myString_4: " << myString_4 << endl;

        myString_4 = myString_3;

        cout << "myString_2: " << myString_2 << endl;
        cout << "myString_3: " << myString_3 << endl;
        cout << "myString_4: " << myString_4 << endl;

        myString_4 = myString_3 = myString_2;

        cout << "myString_2: " << myString_2 << endl;
        cout << "myString_3: " << myString_3 << endl;
        cout << "myString_4: " << myString_4 << endl;

        myString_4= myString_4;

        cout << "myString_4: " << myString_4 << endl;

        //********   operator+= **********//

        MyString myString_5= MyString("Mr Google");
        myString_5+=myString_4+=myString_5;
        cout << "myString_4: " << myString_4 << endl;
        cout << "myString_5: " << myString_5 << endl;

    }
    catch (const char *msg) {
        cout << msg << endl;
    }

}

void logic_operators_test(){
    MyString myString_1 = MyString("Tamar");
    MyString myString_2 = MyString("Tamar");
    MyString myString_3 = MyString("Sara");
    MyString myString_4 = MyString("Rivka");


    //----------------- == -------------------

    cout<<myString_1.c_str()<< " == "<< myString_2.c_str()<<" : "<<(myString_1==myString_2)<<endl;

    cout<<myString_1.c_str()<< " == "<< myString_3.c_str()<<" : "<<(myString_1==myString_3)<<endl;

    //----------------- != -------------------

    cout<<myString_1.c_str()<< " != "<< myString_2.c_str()<<" : "<<(myString_1!=myString_2)<<endl;

    cout<<myString_1.c_str()<< " != "<< myString_3.c_str()<<" : "<<(myString_1!=myString_3)<<endl;

    //----------------- <= -------------------


    cout<<myString_1.c_str()<< " <= "<< myString_2.c_str()<<" : "<<(myString_1<=myString_2)<<endl;

    cout<<myString_1.c_str()<< " <= "<< myString_3.c_str()<<" : "<<(myString_1<=myString_3)<<endl;

    cout<<myString_1.c_str()<< " < "<< myString_2.c_str()<<" : "<<(myString_1<myString_2)<<endl;

    cout<<myString_1.c_str()<< " < "<< myString_3.c_str()<<" : "<<(myString_1<myString_3)<<endl;

    cout<<myString_3.c_str()<< " < "<< myString_1.c_str()<<" : "<<(myString_3<myString_1)<<endl;


    cout<<myString_1.c_str()<< " > "<< myString_2.c_str()<<" : "<<(myString_1>myString_2)<<endl;

    cout<<myString_1.c_str()<< " > "<< myString_3.c_str()<<" : "<<(myString_1>myString_3)<<endl;


    cout<<myString_3.c_str()<< " >"<< myString_1.c_str()<<" : "<<(myString_3>myString_1)<<endl;


    cout<<myString_1.c_str()<< " >= "<< myString_2.c_str()<<" : "<<(myString_1>=myString_2)<<endl;

    cout<<myString_1.c_str()<< " >= "<< myString_3.c_str()<<" : "<<(myString_1>=myString_3)<<endl;


    cout<<myString_3.c_str()<< " >="<< myString_1.c_str()<<" : "<<(myString_3>=myString_1)<<endl;

}