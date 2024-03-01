#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>

std::list<int> func1(std::list<int> l)
{
    std::list<int>::iterator it1=l.begin();

    std::advance(it1,3); //сдвиг вправо на 3
    std::advance(it1,-3); //сдвиг влево на 3
    std::for_each_n(it1,5, [] (auto &x) { x=x*x; });// изменит пять элементов, начиная с итератора it1 в соответствии с функцией

    std::vector<int> values{1,25,125};
    std::vector<int>::iterator first=values.begin();
    std::vector<int>::iterator last=values.end();
    l.insert(l.begin(),first,last); //вставка в начало листа элементы из другого контейнера из диапозона между итераторами first и last
   
    return l;
}

std::vector<int> func2(std::vector<int> n)
{
    std::deque<int> deq;
    std::copy(n.begin(),n.end(), std::front_inserter(deq));

    auto middle_iter=deq.begin()+(n.size()/2);
    std::fill_n(std::inserter(deq,middle_iter),2,-1);
    std::fill_n(std::front_inserter(deq),2,-1);
    std::fill_n(std::back_inserter(deq),2,-1);

    return std::vector<int>(deq.begin(),deq.end());
}

void func3(const std::string& inputFilename, const std::string& outputFilename)
{
    std::ifstream inputFile(inputFilename.c_str());
    std::ofstream outputFile(outputFilename);

    std::istreambuf_iterator<char> begin(inputFile);
    std::istreambuf_iterator<char> end;
    std::ostreambuf_iterator<char> out(outputFile);
    std::copy(begin,end,out);
}

std::deque<int> func4(std::vector<int> n)
{
    std::deque<int> deq;
    std::copy(n.begin(),n.end(),std::inserter(deq,deq.end()));

    return deq;
}

std::vector<int> func5(std::vector<int> n)
{
    return std::vector<int>(n.rbegin(),n.rend());
}

int main()
{
    //TASK 1
    std::list<int> list1;
    std::cout << "How many elements do you want to be in list? " <<std::endl;
    size_t size;
    std::cin >> size;
    for (size_t i=0;i<size;++i)
    {
        int element;
        std::cout << "Enter an element:  ";
        std::cin >> element;
        list1.push_back(element);
    }
    auto result1=func1(list1);
    auto iter1=result1.begin();
    while (iter1!=result1.end())
    {
        std::cout << *iter1 << " ";
        ++iter1;
    }
    std::cout << std::endl;

    //TASK 2
    std::vector<int> v2{10,43,37,23,5,3,65,34};
    auto result2=func2(v2);
    auto iter2=result2.begin();
    while (iter2 != result2.end())
    {
        std::cout << *iter2 << " ";
        ++iter2;
    }
    std::cout << std::endl;

    //TASK 3
    std::string inputFilename;
    std::string outputFilename;
    std::cout << "Enter input filename: " << std::endl;
    std::cin >> inputFilename;
    std::cout << "Enter output filename: " << std::endl;
    std::cin >> outputFilename;
    func3(inputFilename, outputFilename);

    //TASK 4
    std::vector<int> v4{10,23,34,54,76,87,9,89,7,8,98};
    auto result4=func4(v4);
    auto iter4=result4.begin();
    while (iter4 != result4.end())
    {
        std::cout << *iter4 << " ";
        ++iter4;
    }
    std::cout << std::endl;

    //TASK 5
    std::vector<int> v5{1,2,3,4,5,6,7,8,9,10};
    auto result5=func5(v5);
    auto iter5=result5.begin();
    while (iter5 != result5.end())
    {
        std::cout << *iter5 << " ";
        ++iter5;
    }
    std::cout << std::endl;
    return 0;
}