#include <iostream>
#include <vector>
#include <string>

using namespace std;
 double getGradePoints(string grade){
    if(grade == "A" || grade == "a")return 4.0; //(&), also 7777777777777777
    else if(grade == "B" || grade == "b")return 3.0;
    else if(grade == "C+" || grade == "c+")return 2.3;
    else if(grade == "C" || grade == "c")return 2.0;
    else if(grade == "D" || grade == "d")return 1.0;
    else if(grade == "F" || grade == "f")return 0.0;
    else if(grade == "B+" || grade == "b+")return 3.3;
    else{
        cout << "Invalid Input Entered";
        return -1;
    }
 }

 double CGPAcalc(const vector<string>& grades,const vector<int>& credits){
    double totalPoints = 0;
    int totalCredits = 0;
    for (size_t i = 0; i < grades.size(); i++){
        double gradePoint = getGradePoints(grades[i]);
        if(gradePoint < 0)return -1;
        totalPoints += gradePoint * credits[i];
        totalCredits += credits[i];

    }
    if(totalCredits == 0)return -1;
    return totalPoints / totalCredits;
    
 }


int main(){
    int numbCourse;
    vector<string> grades;
    vector<int> credits;
    cout << "Enter the number of courses: ";
    cin >> numbCourse;
for(int i = 0; i < numbCourse;i++){
    string grade;
    int credit;
cout << "Enter grade for course " << i + 1 << " (e.g A,B+,C): ";
cin >> grade;
grades.push_back(grade);
cout << "Enter credit hours for course " << i + 1 << ": ";
cin >> credit;
credits.push_back(credit);
}

double CGPA = CGPAcalc(grades,credits);
if(CGPA < 0){
    cout << "Error!";
}else{
    cout << "Your CGPA is:" << CGPA << endl;
}
return 0;

}