//
// Created by user on 13.11.2017.
//
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include <queue>
#include "Cashier.h"
#include "Barista.h"
#include "Customer.h"
#include "iomanip"
using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

struct CustomCompare{
    bool operator()(const Customer& lhs, const Customer& rhs) {
        return lhs.curTime > rhs.curTime;
    }
};

struct CustomCompare1{
    bool operator()(const Customer& lhs, const Customer& rhs) {
        return lhs.price < rhs.price;
    }
};
int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 2;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;


    ifstream infile(argv[1]);
    string line = "";
    int n, islem;
    getline(infile, line);
    n = stoi(line);
    cout << "number of Cashier: " << n << endl;

    getline(infile, line);
    islem = stoi(line);
    cout << "number of Customer: " << islem << endl;

    vector<Cashier> cashier2;
    vector<Customer> customer2;
    vector<Barista> bar2;
    vector<Cashier> cashier;
    vector<Customer> customer;
    vector<Barista> bar;
    vector<priority_queue<Customer,vector<Customer>,CustomCompare1>> queue;
    priority_queue<Customer,vector<Customer>, CustomCompare> pq;
    priority_queue<Customer,vector<Customer>, CustomCompare> pq2;
    priority_queue<Customer,vector<Customer>, CustomCompare> cashierQ;
    priority_queue<Customer,vector<Customer>, CustomCompare> cashierQ2;
    priority_queue<Customer,vector<Customer>,CustomCompare1> baristaQ;

    for (int i = 0; i < n; i++) {
        Cashier a(i);
        cashier2.push_back(a);
        cashier.push_back(a);
    }

    for (int i = 0; i < n / 3; i++) {
        Barista a(i);
        bar2.push_back(a);
        bar.push_back(a);
        priority_queue<Customer,vector<Customer>,CustomCompare1> baristaQ;
        queue.push_back(baristaQ);
    }

    for (int i = 0; i < islem; i++) {
        vector<string> words;
        getline(infile, line);
        split1(line, words);
        Customer c(i, stod(words[0]), stod(words[1]), stod(words[2]), stod(words[3]));
        pq2.push(c);
        pq.push(c);
        customer2.push_back(c);
        customer.push_back(c);
    }

    cout << "input file has been read" << endl;

    int maxCashQue=0;
    int maxBarQue=0;
    float last=0;
    while(!pq.empty()) {
        Customer c = pq.top();
        int order = c.index;
        if (customer[order].getStatus() == 1) {
            int count = 0;
            for (int i = 0; i < cashier.size(); i++) {
                if (customer[order].getArrivalTime() >= cashier[i].getEndTime()) {
                    cashier[i].setAvailable(true);
                }
                if (cashier[i].getAvailable()) {
                    cashier[i].setAvailable(false);
                    cashier[i].setEndTime(customer[order].getArrivalTime() + customer[order].getOrderTime());
                    cashier[i].setUtilization(cashier[i].getUtilization() + customer[order].getOrderTime());
                    customer[order].setBarArrival(cashier[i].getEndTime());
                    customer[order].cashierInt = i;
                    customer[order].setCurTime(customer[order].getBarArrival());
                    break;
                } else {
                    count++;
                }
            }

            if (count == cashier.size()) {
                cashierQ.push(customer[order]);
                if (cashierQ.size() > maxCashQue)
                    maxCashQue = cashierQ.size();
            } else {
                customer[order].setStatus(2);
                pq.push(customer[order]);
            }
        } else if (customer[order].getStatus() == 2) {
            if (!cashierQ.empty()) {
                Customer c1 = cashierQ.top();
                int index = customer[order].cashierInt;
                int order1 = c1.index;
                cashier[index].setAvailable(false);
                cashier[index].setEndTime(cashier[index].getEndTime() + customer[order1].getOrderTime());
                cashier[index].setUtilization(cashier[index].getUtilization() + customer[order1].getOrderTime());
                customer[order1].setBarArrival(cashier[index].getEndTime());
                customer[order1].cashierInt = index;
                customer[order1].setCurTime(customer[order1].getBarArrival());
                customer[order1].setStatus(2);
                pq.push(customer[order1]);
                cashierQ.pop();
            }

            customer[order].setStatus(3);
            pq.push(customer[order]);

        } else if (customer[order].getStatus() == 3) {
            int count = 0;
            for (int i = 0; i < bar.size(); i++) {
                if (customer[order].getBarArrival() >= bar[i].getEndTime()) {
                    bar[i].setAvailable(true);
                }

                if (bar[i].getAvailable()) {
                    bar[i].setAvailable(false);
                    bar[i].setEndTime(customer[order].getBarArrival() + customer[order].getBrewTime());
                    bar[i].setUtilization(bar[i].getUtilization() + customer[order].getBrewTime());
                    customer[order].setBarEnd(bar[i].getEndTime());
                    customer[order].setCurTime(customer[order].getBarEnd());
                    customer[order].barInt = i;
                    customer[order].bar = true;
                    last = customer[order].getBarEnd();
                    break;
                } else {
                    count++;
                }
            }

            if (count == bar.size()) {
                baristaQ.push(customer[order]);
                if (baristaQ.size() > maxBarQue)
                    maxBarQue = baristaQ.size();
            } else {
                customer[order].setStatus(4);
                pq.push(customer[order]);
            }
        } else {
            if (!baristaQ.empty()) {
                Customer c1 = baristaQ.top();
                int order1 = c1.index;
                int index = customer[order].barInt;
                bar[index].setAvailable(false);
                bar[index].setEndTime(bar[index].getEndTime() + customer[order1].getBrewTime());
                bar[index].setUtilization(bar[index].getUtilization() + customer[order1].getBrewTime());
                customer[order1].setBarEnd(bar[index].getEndTime());
                customer[order1].barInt = (index);
                customer[order1].setCurTime(customer[order1].getBarEnd());
                customer[order1].setStatus(4);
                pq.push(customer[order1]);
                last = customer[order1].getBarEnd();
                baristaQ.pop();
            }
        }
        pq.pop();
    }

    int maxCashQue2=0;
    double last2=0;
    while(!pq2.empty()){
        Customer c=pq2.top();
        int order=c.index;
        if(customer2[order].getStatus()==1){
            int count=0;
            for(int i=0;i<cashier2.size();i++){
                if(customer2[order].getArrivalTime() >= cashier2[i].getEndTime()) {
                    cashier2[i].setAvailable(true);
                }
                if(cashier2[i].getAvailable()){
                    cashier2[i].setAvailable(false);
                    cashier2[i].setEndTime(customer2[order].getArrivalTime() + customer2[order].getOrderTime());
                    cashier2[i].setUtilization(cashier2[i].getUtilization() + customer2[order].getOrderTime());
                    customer2[order].setBarArrival(cashier2[i].getEndTime());
                    customer2[order].cashierInt=i;
                    customer2[order].setCurTime(customer2[order].getBarArrival());
                    break;
                }
                else{
                    count++;
                }
            }

            if(count==cashier2.size()) {
                cashierQ2.push(customer2[order]);
                if(cashierQ2.size()>maxCashQue2)
                    maxCashQue2=cashierQ2.size();
            }

            else{
                customer2[order].setStatus(2);
                pq2.push(customer2[order]);
            }
        }
        else if(customer2[order].getStatus()==2){
            if(!cashierQ2.empty()){
                Customer c1=cashierQ2.top();
                int index=customer2[order].cashierInt;
                int order1=c1.index;
                cashier2[index].setAvailable(false);
                cashier2[index].setEndTime(cashier2[index].getEndTime() + customer2[order1].getOrderTime());
                cashier2[index].setUtilization(cashier2[index].getUtilization() + customer2[order1].getOrderTime());
                customer2[order1].setBarArrival(cashier2[index].getEndTime());
                customer2[order1].cashierInt=index;
                customer2[order1].setCurTime(customer2[order1].getBarArrival());
                customer2[order1].setStatus(2);
                pq2.push(customer2[order1]);
                cashierQ2.pop();
            }

            customer2[order].setStatus(3);
            pq2.push(customer2[order]);

        }

        else if(customer2[order].getStatus()==3){
            int count=0;
            for(int i=0;i<bar2.size();i++){
                if(i==customer2[order].cashierInt/3) {
                    if (customer2[order].getBarArrival() >= bar2[i].getEndTime()) {
                        bar2[i].setAvailable(true);
                    }

                    if (bar2[i].getAvailable()) {
                        bar2[i].setAvailable(false);
                        bar2[i].setEndTime(customer2[order].getBarArrival() + customer2[order].getBrewTime());
                        bar2[i].setUtilization(bar2[i].getUtilization() + customer2[order].getBrewTime());
                        customer2[order].setBarEnd(bar2[i].getEndTime());
                        customer2[order].setCurTime(customer2[order].getBarEnd());
                        customer2[order].barInt = i;
                        customer2[order].bar = true;
                        last2 = customer2[order].getBarEnd();
                        break;
                    } else {
                        count++;
                    }
                }
            }

            if(count==1){
                queue[customer2[order].cashierInt/3].push(customer2[order]);
                if(queue[customer2[order].cashierInt/3].size()>bar2[customer2[order].cashierInt/3].maxQue)
                    bar2[customer2[order].cashierInt/3].maxQue=queue[customer2[order].cashierInt/3].size();
            }

            else{
                customer2[order].setStatus(4);
                pq2.push(customer2[order]);
            }
        }

        else{
            if(!queue[customer2[order].cashierInt/3].empty()){
                Customer c1=queue[customer2[order].cashierInt/3].top();
                int order1=c1.index;
                int index=customer2[order].barInt;
                bar2[index].setAvailable(false);
                bar2[index].setEndTime(bar2[index].getEndTime() + customer2[order1].getBrewTime());
                bar2[index].setUtilization(bar2[index].getUtilization() + customer2[order1].getBrewTime());
                customer2[order1].setBarEnd(bar2[index].getEndTime());
                customer2[order1].barInt=(index);
                customer2[order1].setCurTime(customer2[order1].getBarEnd());
                customer2[order1].setStatus(4);
                pq2.push(customer2[order1]);
                last2=customer2[order1].getBarEnd();
                queue[customer2[order].cashierInt/3].pop();
            }
        }
        pq2.pop();
    }
    ofstream myfile;
    myfile.open(argv[2]);
    myfile << std::fixed;
    myfile << std::setprecision(2);

    myfile<<last<<endl;
    myfile<<maxCashQue<<endl;
    myfile<<maxBarQue<<endl;
    for(int i=0;i<cashier.size();i++){
        myfile << (cashier[i].utilizationTime / last) << endl;
    }

    for(int i=0;i<bar.size();i++)
        myfile<<(bar[i].utilizationTime / last)<<endl;

    for(int i=0;i<customer.size();i++)
        myfile<<customer[i].getBarEnd()-customer[i].getArrivalTime()<<endl;

    myfile<<endl;
    myfile<<(last2)<<endl;
    myfile<<maxCashQue2<<endl;
    for(int i=0;i<bar2.size();i++)
        myfile<<bar2[i].maxQue<<endl;

    for(int i=0;i<cashier2.size();i++){
        myfile << (cashier2[i].utilizationTime / last2) << endl;
    }

    for(int i=0;i<bar2.size();i++)
        myfile<<(bar2[i].utilizationTime / last2)<<endl;

    for(int i=0;i<customer2.size();i++)
        myfile<<(customer2[i].getBarEnd()-customer2[i].getArrivalTime())<<endl;

    myfile.close();

    return 0;
}
