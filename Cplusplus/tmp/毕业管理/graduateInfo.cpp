#include "graduateInfo.h"

template<>
class std::less<cjj::PeopleInfo> {
    bool operator()(const cjj::PeopleInfo& p1, const cjj::PeopleInfo& p2) const
    {
        return p1._name < p2._name;
    }
};

namespace cjj
{
    GraduateInfo::GraduateInfo()
    {
        string name;
        string id;
        _fio.open("./info.txt", std::ios::in);
        while (!_fio.eof())
        {
            _fio >> name >> id;
            _page.push_back(PeopleInfo(name, id));
        }
    }

    void GraduateInfo::AddInfo()
    {
        string name;
        string id;
        cout << "info :";
        cin >> name >> id;

        _page.push_back(PeopleInfo(name, id));
    }

    void GraduateInfo::DelInfoByName(const string& name)
    {
        auto it = _page.begin();

        while (it != _page.end()) 
        {
            if (it->_name == name)
            {
                cout << "找到了" << endl;
                _page.erase(it);
                return;
            }
            ++it;
        }
        cout << "没找到" << endl;
    }

    void GraduateInfo::DelInfoByID(const string& id)
    {
        //
    }

    void GraduateInfo::Show()
    {
        auto it = _page.begin();

        while (it != _page.end())
        {
            cout << it->_name <<  " " << it->_id << endl;

            ++it;
        }
    }



    void GraduateInfo::Sort()
    {
        

        std::sort(_page.begin(), _page.end());
    }

    void GraduateInfo::ModifyByName(const string& name)
    {
        auto it = _page.begin();

        while (it != _page.end())
        {
            if (it->_name == name)
            {
                cout << "找到了" << endl;
                it->_name = "asdasdasd";
                return;
            }
            ++it;
        }
        cout << "没找到" << endl;
    }
}
