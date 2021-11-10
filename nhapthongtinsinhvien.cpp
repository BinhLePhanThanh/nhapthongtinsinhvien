#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
struct DoB
{
    int date, month, year;
    std::string dob;
    DoB() = default;
    DoB(int a)
    {

        do
        {
            do
            {
                std::cout << "nhap ngay sinh be hon 32 va lon hon 0: " << std::endl;
                std::cin >> date;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            } while (true);
        } while (date > 31 || date < 1);
        do
        {
            while (true)
            {
                std::cout << "nhap thang sinh be hon 13 va lon hon 0 " << std::endl;
                std::cin >> month;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
        } while (month > 12 || month < 1);
        do
        {
            while (true)
            {
                std::cout << "nhap nam sinh lon hon 0, co 4 chu so lon hon 1960, nho hon 2022: " << std::endl;
                std::cin >> year;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
        } while (year < 0 || year <= 1960 || year >= 2021 || year>9999);
        ignoreLine();
        dob += std::to_string(date) + '/' + std::to_string(month) + '/' + std::to_string(year);
    }
    std::string& returnDoB()
    {
        return this->dob;
    }
};
void removeSpaveFromBeginningAndEndOfString(std::string& primitiveString)
{
    while (*(primitiveString.begin()) == ' ')
    {
        primitiveString.erase(primitiveString.begin());
    }
    while (*(primitiveString.end() - 1) == ' ')
    {
        primitiveString.erase(primitiveString.end() - 1);
    }
}
void lowerCaseForStringWithJustOneSpaceBetween(std::string& primitiveString)
{
    for (int i = 0; i < primitiveString.length() - 2; i++)
    {
        while (*(primitiveString.begin() + i) == ' ' && *(primitiveString.begin() + i + 1) == ' ')
        {
            primitiveString.erase(primitiveString.begin() + i);
        }
    }
    while (*(primitiveString.begin()) == ' ')
    {
        primitiveString.erase(primitiveString.begin());
    }
    while (*(primitiveString.end() - 1) == ' ')
    {
        primitiveString.erase(primitiveString.end() - 1);
    }
    for (auto& i : primitiveString)
    {
        i = tolower(i);
    }
}
void setSpaceBetweenTwoWordByOne(std::string& primitiveString)
{
    for (int i = 0; i < primitiveString.length() - 2; i++)
    {
        while (*(primitiveString.begin() + i) == ' ' && *(primitiveString.begin() + i + 1) == ' ')
        {
            primitiveString.erase(primitiveString.begin() + i);
        }
    }
    while (*(primitiveString.begin()) == ' ')
    {
        primitiveString.erase(primitiveString.begin());
    }
    while (*(primitiveString.end() - 1) == ' ')
    {
        primitiveString.erase(primitiveString.end() - 1);
    }
}
void toLowerCaseString(std::string& primitiveString)
{
    for (auto& i : primitiveString)
    {
        i = tolower(i);
    }
}
void splitStringBySpaceToVector(std::string& theStringNeedSplit, std::vector<std::string>& theVectorThatContainPartsOfString)
{
    std::string temporaryStringContainPartsOftheStringNeedSplit;
    int currentPosition = 0;
    theStringNeedSplit.push_back(' ');
denday:
    while (*(theStringNeedSplit.begin() + currentPosition) != ' ')
    {
        temporaryStringContainPartsOftheStringNeedSplit += *(theStringNeedSplit.begin() + currentPosition);
        currentPosition++;
    }
    theVectorThatContainPartsOfString.push_back(temporaryStringContainPartsOftheStringNeedSplit);
    temporaryStringContainPartsOftheStringNeedSplit.clear();
    currentPosition++;
    if (theStringNeedSplit.begin() + currentPosition == theStringNeedSplit.end())
    {
        return;
    }
    goto denday;
}
void upperCaseTheFirstCharacterOfStringsInsideVector(std::vector<std::string>& theVectorThatContainPartsOfString)
{
    for (auto& i : theVectorThatContainPartsOfString)
    {
        *(i.begin()) = toupper(*(i.begin()));
    }
}
bool isValidateName(std::string& primitiveString)
{
    for (auto& i : primitiveString)
    {
        if (primitiveString.size() < 2)
            return false;
        if ((65 <= i && 90 >= i) || (97 <= i && 122 >= i))
        {
            continue;
        }
        else return false;
        return true;
    }
}
class SinhVien
{
    std::string studentName, lop;
    std::vector<std::string> theVectorContainAllPartOfstudentName;
    DoB dateOfBirth;
    int IdOfEachSinhVien;
public:

    int returnIdOfSinhVien()
    {
        return this->IdOfEachSinhVien;
    }
    static std::vector<SinhVien> theVectorThatContainsAllSinhVien;
    static int autoIncrementNumber;
    SinhVien()
    {
        IdOfEachSinhVien = autoIncrementNumber++;
        std::cout << "nhap ten sinh vien: " << std::endl;
        std::getline(std::cin, this->studentName);
        while (!isValidateName(this->studentName))
        {
            std::cout << "ten sinh vien phai lon hon hoac bang 2 ky tu va ko co ky tu dac biet: " << std::endl;
            std::getline(std::cin, this->studentName);
        }
        toLowerCaseString(this->studentName);
        setSpaceBetweenTwoWordByOne(this->studentName);
        splitStringBySpaceToVector(this->studentName, this->theVectorContainAllPartOfstudentName);
        upperCaseTheFirstCharacterOfStringsInsideVector(this->theVectorContainAllPartOfstudentName);
        this->studentName.clear();
        for (auto& i : this->theVectorContainAllPartOfstudentName)
        {
            this->studentName += (i + " ");
        }
        setSpaceBetweenTwoWordByOne(this->studentName);
        std::cout << "nhap lop sinh vien: " << std::endl;
        std::getline(std::cin, this->lop);
        std::cout << "nhap ngay, thang, nam sinh sinh vien theo dung dinh dang- day/month/year: " << std::endl;
        dateOfBirth = DoB(0);
        standardizedDateOfBirth(dateOfBirth.returnDoB());
    }
    void standardizedDateOfBirth(std::string& ngaythangnam)
    {
        // dd/mm/yyyy
        if (ngaythangnam.size() == 10)
            return;
        int currentPosition = 0;
        int count = 1;
        std::string::iterator it = ngaythangnam.begin();
        while (*(it + currentPosition) != '/')
        {
            count++;
            currentPosition++;
        }
        if (count == 2)
        {
            ngaythangnam.insert(0, "0");
            currentPosition++;
        }
        count = 0;

        do //02/2/
        {
            count++;
            currentPosition++;
        } while (*(it + currentPosition) != '/');
        if (count == 2)
        {
            ngaythangnam.insert(currentPosition - 1, "0");
        }
    }
public:
    static void renameForObjectStudent(SinhVien& sinhvien)
    {
        std::getline(std::cin, sinhvien.studentName);
        while (!isValidateName(sinhvien.studentName))
        {
            std::cout << "ten sinh vien phai lon hon hoac bang 2 ky tu va ko co ki tu dac biet: " << std::endl;
            std::getline(std::cin, sinhvien.studentName);
        }
        toLowerCaseString(sinhvien.studentName);
        setSpaceBetweenTwoWordByOne(sinhvien.studentName);
        sinhvien.theVectorContainAllPartOfstudentName.clear();
        splitStringBySpaceToVector(sinhvien.studentName, sinhvien.theVectorContainAllPartOfstudentName);
        upperCaseTheFirstCharacterOfStringsInsideVector(sinhvien.theVectorContainAllPartOfstudentName);
        sinhvien.studentName.clear();
        for (auto& i : sinhvien.theVectorContainAllPartOfstudentName)
        {
            sinhvien.studentName += (i + " ");
        }
        sinhvien.studentName.erase(sinhvien.studentName.end() - 1);

    }
    static void ChangeDateOfBirth(SinhVien& sinhvien)
    {
        sinhvien.dateOfBirth = DoB(0);
    }
    static void ChangeGradeOfSinhVien(SinhVien& sinhvien)
    {
        std::getline(std::cin, sinhvien.lop);
    }
    static void ChangeInformationOfSinhVien(SinhVien& sinhvien)
    {
        std::cout << "sua ten sinh vien: ";
        for (auto& i : sinhvien.theVectorContainAllPartOfstudentName)
        {
            std::cout << i << " ";
        }
        std::cout << " thanh: ";
        renameForObjectStudent(sinhvien);
        std::cout << std::endl;
        std::cout << "sua ngay sinh cua sinh vien: " << sinhvien.dateOfBirth.returnDoB() << " thanh dung dinh dang day/month/year: ";
        ChangeDateOfBirth(sinhvien);

        std::cout << std::endl;
        std::cout << "sua lop sinh vien: " << sinhvien.lop << " thanh: ";
        ChangeGradeOfSinhVien(sinhvien);
        std::cout << std::endl;
    }
    static void themsinhvienmoi()
    {
        SinhVien sinhvienmoi;
        SinhVien::theVectorThatContainsAllSinhVien.push_back(sinhvienmoi);
    }
    static void removeSinhVienObjectFromList(int n)
    {
        theVectorThatContainsAllSinhVien.erase(theVectorThatContainsAllSinhVien.begin() + n);
    }
    static void writeToConsoleSinhVienObjectInformation(SinhVien& sinhvien)
    {
        std::cout << "Ma so sinh vien: " << sinhvien.IdOfEachSinhVien << std::endl;
        std::cout << "Ten: " << sinhvien.studentName;

        std::cout << "\nLop: " << sinhvien.lop << std::endl;
        std::cout << "Ngay thang nam sinh: " << sinhvien.dateOfBirth.returnDoB() << std::endl;
    }
    static void saveToStorageFile()
    {
        std::ofstream texttxt;
        texttxt.open("text.txt");

        for (auto& i : theVectorThatContainsAllSinhVien)
        {

            texttxt << "Ten: " << i.studentName << '\n' << "Lop: " << i.lop << '\n' << "Date of birth: " << i.dateOfBirth.returnDoB() << '\n' << "Ma so sinh vien la: " << i.IdOfEachSinhVien << std::endl;
        }

    }
    static void searchByClient()
    {
        std::cout << "nhap thong tin muon tim kiem, in ra toan bo sinh vien chua thong tin do: " << std::endl;
        std::string clientGiveInformation;
        std::getline(std::cin, clientGiveInformation);
        std::string advancedClientGiveInformation = clientGiveInformation;
        std::vector<std::string> partsOfadvancedClientGiveInformation;
        if (advancedClientGiveInformation.size() < 2)
        {
            removeSpaveFromBeginningAndEndOfString(advancedClientGiveInformation);
            *(advancedClientGiveInformation.begin()) = toupper(*(advancedClientGiveInformation.begin()));



        }
        else
        {


            lowerCaseForStringWithJustOneSpaceBetween(advancedClientGiveInformation);

            splitStringBySpaceToVector(advancedClientGiveInformation, partsOfadvancedClientGiveInformation);
            upperCaseTheFirstCharacterOfStringsInsideVector(partsOfadvancedClientGiveInformation);
            advancedClientGiveInformation.clear();
            for (auto& i : partsOfadvancedClientGiveInformation)
            {
                advancedClientGiveInformation += (i + " ");
            }
            advancedClientGiveInformation.erase(advancedClientGiveInformation.end() - 1);
        }
        int count = 0;
        for (auto& i : SinhVien::theVectorThatContainsAllSinhVien)
        {
            if (i.studentName.find(clientGiveInformation) != std::string::npos || i.dateOfBirth.returnDoB().find(clientGiveInformation) != std::string::npos || i.lop.find(clientGiveInformation) != std::string::npos || i.studentName.find(advancedClientGiveInformation) != std::string::npos || i.dateOfBirth.returnDoB().find(advancedClientGiveInformation) != std::string::npos || i.lop.find(advancedClientGiveInformation) != std::string::npos)

            {
                SinhVien::writeToConsoleSinhVienObjectInformation(i);
                count++;
            }
        }
        if (count == 0)
        {
            std::cout << "khong tim duoc sinh vien nao thoa man!" << std::endl;
        }
    }
};
int SinhVien::autoIncrementNumber = 0;
std::vector<SinhVien>SinhVien::theVectorThatContainsAllSinhVien;

int main()
{

reset:

    int status;
    int choice;
    std::cout << "nhan 1 de them sinh vien vao danh sach: " << std::endl;
    std::cout << "nhan 2 de chinh sua thong tin sinh vien theo ma so, so thu tu bat dau tu 0: " << std::endl;
    std::cout << "nhan 3 day thong tin len txt: " << std::endl;
    std::cout << "nhan 4 de xoa sinh vien theo ma so: " << std::endl;
    std::cout << "nhan 5 de tim kiem bang 1 chuoi or 1 ky tu: " << std::endl;
    std::cout << "nhan 6 de tim kiem bang ma so sinh vien bat dau tu 0: " << std::endl;
    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
            std::cin.clear();
            ignoreLine();
            continue;
        }
        break;
    }
    std::cin.ignore(10, '\n');
    switch (choice)
    {
        case 1://1 de them sinh vien vao danh sach
        {
            SinhVien::themsinhvienmoi();
            std::cout << "them 1 sinh vien thanh cong, ma so sinh vien nay la: " << SinhVien::autoIncrementNumber - 1 << std::endl;
            std::cout << "Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;

        }
        case 2://chinh sua thong tin sinh vien dua tren id
        {
            if (SinhVien::theVectorThatContainsAllSinhVien.size() == 0)
            {
                std::cout << "ko co gi trong danh sach de sua: " << std::endl;
                std::cout << " Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
                while (true)
                {
                    std::cin >> status;
                    if (std::cin.fail())
                    {
                        std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                        std::cin.clear();
                        ignoreLine();
                        continue;
                    }
                    break;
                }
                std::cin.ignore(10, '\n');
                if (status == 1) goto reset;
                break;
            }
            std::cout << "nhap ma so sinh vien muon tim: " << std::endl;
            int id;
            std::cin >> id;
            std::cin.ignore(10, '\n');
            int count = 0;
            for (auto& i : SinhVien::theVectorThatContainsAllSinhVien)
            {

                if (i.returnIdOfSinhVien() == id)
                {
                    break;
                }
                count++;
            }
            if (count == SinhVien::theVectorThatContainsAllSinhVien.size())
            {
                std::cout << "khong ton tai sinh vien co ma: " << id << std::endl;
                goto reset;
            }
            SinhVien::ChangeInformationOfSinhVien(SinhVien::theVectorThatContainsAllSinhVien[count]);
            std::cout << " Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;
        }
        case 3://day thong tin len txt
        {
            SinhVien::saveToStorageFile();
            std::cout << "Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;
        }
        case 4:// dang xoa dua theo thu tu trong list can chuyen qua xoa bang id
        {

            if (SinhVien::theVectorThatContainsAllSinhVien.size() == 0)
            {
                std::cout << "ko co gi trong danh sach de xoa: " << std::endl;
                std::cout << " Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
                while (true)
                {
                    std::cin >> status;
                    if (std::cin.fail())
                    {
                        std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                        std::cin.clear();
                        ignoreLine();
                        continue;
                    }
                    break;
                }
                std::cin.ignore(10, '\n');
                if (status == 1) goto reset;
                break;
            }
            std::cout << "nhap ma so sinh vien muon xoa: " << std::endl;
            int id;
            while (true)
            {
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            int count = 0;
            for (auto& i : SinhVien::theVectorThatContainsAllSinhVien)
            {
                if (i.returnIdOfSinhVien() == id)
                {
                    break;
                }
                count++;
            }
            if (count == SinhVien::theVectorThatContainsAllSinhVien.size())
            {
                std::cout << "khong ton tai sinh vien co ma: " << id << std::endl;
                goto reset;
            }
            SinhVien::removeSinhVienObjectFromList(count);
            std::cout << " Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;
        }
        case 5:
        {

            if (SinhVien::theVectorThatContainsAllSinhVien.size() == 0)
            {
                std::cout << "ko co gi trong vector de tim: " << std::endl;
                std::cout << "Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
                while (true)
                {
                    std::cin >> status;
                    if (std::cin.fail())
                    {
                        std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                        std::cin.clear();
                        ignoreLine();
                        continue;
                    }
                    break;
                }
                std::cin.ignore(10, '\n');
                if (status == 1) goto reset;
                break;
            }
            std::cout << "bat dau tim kiem: " << std::endl;
            SinhVien::searchByClient();
            std::cout << "Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;
        }
        case 6:
        {
            if (SinhVien::theVectorThatContainsAllSinhVien.size() == 0)
            {
                std::cout << "ko co gi trong danh sach de tim: " << std::endl;
                std::cout << " Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
                while (true)
                {
                    std::cin >> status;
                    if (std::cin.fail())
                    {
                        std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                        std::cin.clear();
                        ignoreLine();
                        continue;
                    }
                    break;
                }
                std::cin.ignore(10, '\n');
                if (status == 1) goto reset;
                break;
            }
            std::cout << "nhap ma so sinh vien muon tim: " << std::endl;
            int id;
            while (true)
            {
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            int count = 0;
            for (auto& i : SinhVien::theVectorThatContainsAllSinhVien)
            {

                if (i.returnIdOfSinhVien() == id)
                {
                    break;
                }
                count++;
            }
            if (count == SinhVien::theVectorThatContainsAllSinhVien.size())
            {
                std::cout << "khong ton tai sinh vien co ma: " << id << std::endl;
                goto reset;
            }
            SinhVien::writeToConsoleSinhVienObjectInformation(SinhVien::theVectorThatContainsAllSinhVien[count]);
            std::cout << "Done! nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;
        }
        default:
        {
            std::cout << "Nhap tu 1 den 6 thoi: " << std::endl;
            std::cout << "Nhan 1 de tiep tuc,0 de ket thuc chuong trinh" << std::endl;
            while (true)
            {
                std::cin >> status;
                if (std::cin.fail())
                {
                    std::cout << "nhap khong hop le, nhap lai di: " << std::endl;
                    std::cin.clear();
                    ignoreLine();
                    continue;
                }
                break;
            }
            std::cin.ignore(10, '\n');
            if (status == 1) goto reset;
            break;
        }

    }
    return 0;
}

