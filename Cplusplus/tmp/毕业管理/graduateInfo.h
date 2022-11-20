#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>



namespace cjj {

    using std::string;
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;

    struct PeopleInfo {
        string _name;
        string _id;
        PeopleInfo(const string& name, const string& id) :_name(name), _id(id) {}
        bool operator<(const PeopleInfo& p) const { return _name < p._name;}
    };



    class GraduateInfo {
    public:

        GraduateInfo();
        void AddInfo();
        void DelInfoByName(const string& name);
        void DelInfoByID(const string& id);
        void Show();
        void Sort();
        void ModifyByName(const string& name);

    private:
        vector<PeopleInfo> _page;
        std::fstream _fio;
    };

}
