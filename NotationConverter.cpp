#include "NotationConverter.hpp"
#include <cctype>
using namespace std;

string NotationConverter::postfixToInfix(string inStr){

    //error for incorrect format
    if(!isalpha(inStr[0]))
        throw ("Incorrect format for postfix");

    //storing operation and variables on deques
    for(unsigned int i=0; i<inStr.size(); i++){//iterating through string
        if(!isspace(inStr[i])){//doesnt read white space

            if(inStr[i]=='+'||inStr[i]=='-'||inStr[i]=='*'||inStr[i]=='/'){
                operation.insertBack(inStr[i]);//storing + - * /
            }
            else
                variable.insertBack(inStr[i]);//storing X Y Z A B
        }
    }//end sorting

    //error for incorrect numb of signs or variable
    if(operation.size()!=variable.size()-1){
        throw ("Incorrect format for postfix");
    }

    int paren_set_num = operation.size();//Number of Parenthesis sets for equation
    newfix.insertBack('(');//first parenthesis

    for(int i=1; i<paren_set_num-1;i++){
        newfix.insertBack('(');//added based on number of operations
    }

    while(variable.empty()==false){//loops till variable deque empty
        newfix.insertBack(variable.front());
        variable.removeFront();

        if(operation.empty()==false){//adding operators and brackets
            if(operation.size()==2){//when last two operation remains
                newfix.insertBack(')');
                newfix.insertBack(operation.back());
                newfix.insertBack('(');

                operation.removeBack();
            }

            else{
                newfix.insertBack(operation.front());
                operation.removeFront();
            }
        }
    }

    newfix.insertBack(')');
    //end storing

    return toString();//return string
}

string NotationConverter::postfixToPrefix(string inStr){
    return infixToPrefix(postfixToInfix(inStr));
}


string NotationConverter::infixToPrefix(string inStr){
    
    //error if no (
    if(inStr[0] != '('){
        throw ("Incorrect Infix formatting");
    }

    for(unsigned int i = 0; i < inStr.size(); i++){//iterating through the entire string
        
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){//stops at )
            if(inStr[i] != ' '){//avoid white space
                
                if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){

                    if(inStr[i-2] == ')'){//if theres a parenthesis ) add front instead of back
                        newfix.insertFront(inStr[i]);
                    }
                    
                    else{//adding back
                        newfix.insertBack(inStr[i]);
                    }
                }
                //Inserts the operands into the temporary deque
                else if(inStr[i] != '('){
                    variable.insertBack(inStr[i]);
                }
            }
            
            i++;//iterate while
        }

        int num = variable.size();

        for(int i = 0; i < num; i++){//adding the variables to main deque
            
            newfix.insertBack(variable.front());
            variable.removeFront();
        }
    }

    return toString();//return string
}

string NotationConverter::infixToPostfix(string inStr){
    
    //same throw statement for both infixes
    if(inStr[0] != '('){
        throw ("incorrect infix formatting");
    }

    for(unsigned int i=0; i<inStr.size(); i++){//iterating through the entire string

        while(inStr[i]!=')' && inStr[i]!=*inStr.end()){//stops at )
            if(inStr[i] != ' '){//no spaces read

                if(inStr[i]=='+'||inStr[i]=='-'||inStr[i]=='*'||inStr[i]=='/'){
                    operation.insertBack(inStr[i]);//storing + - * /
                }  

                else if(inStr[i]!='('){
                    newfix.insertBack(inStr[i]);
                }
            }
        i++; //iterate through till )
        }//end sorting
    
    int num_operation = operation.size();

        for(int i = 0; i < num_operation; i++){
        
            if(operation.size() == 2){//if two operation maintain order by removing from back
                newfix.insertBack(operation.back());
                operation.removeBack();
            }
            else{
                newfix.insertBack(operation.front());
                operation.removeFront();
            }
        }//end storing

    }//end main iterator

    return toString();//return string
}


string NotationConverter::prefixToInfix(string inStr){
    
    //if prefix does not start with operation
    if(inStr[0] != '+' && inStr[0] != '-' && inStr[0] != '*' && inStr[0] != '/')
        throw ("Incorrect prefix format");

    bool paren_required = false; //determines if paren needed
    int paren_count = 0;        //makes sure parenthesis are in pairs

    for(unsigned int i = 0; i < inStr.size(); i++){// interating through the loops
        if(inStr[i] != ' '){

            if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){//inserting operations
                
                operation.insertBack(inStr[i]);
                newfix.insertBack('(');
                paren_count++;
                paren_required = false;
            }
            else{//inserting variables in the deque

                newfix.insertBack(inStr[i]);

                if(paren_required == true){//parenthesis insert
                    newfix.insertBack(')');
                    paren_count--;
                }

                if(operation.empty() == false){//insert operation
                    newfix.insertBack(operation.back());
                    newfix.removeBack();
                    paren_required = true;   //Left parenthesis is needed in the next loop
                }
            }
        }
    }

    //check parentheis count to add parenthesis
    if(paren_count != 0){
        while(paren_count != 0){
            newfix.insertBack(')');
            paren_count--;
        }
    }

    return toString();//return string
}

string NotationConverter::prefixToPostfix(string inStr){
    return infixToPostfix(prefixToInfix(inStr));
}


string NotationConverter::toString(){
    string convertedstring;
    
    if(newfix.empty()==true)
        return convertedstring;
    
    int size = newfix.size();

    if(newfix.front() == ')'){
        convertedstring.pop_back();
    }

    convertedstring += newfix.front();

    if(newfix.front()!='('){
        convertedstring += ' ';
    
        newfix.removeFront();
    }

    convertedstring.pop_back();

    return convertedstring;
}