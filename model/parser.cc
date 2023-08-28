#include "parser.h"
namespace s21{
    void s21::ObjParser::ParseFile(QString &filename, QVector<double>& vertex, QVector<int>& face)
    {
            QFile file(filename);
            if(!file.exists() || !file.open(QIODevice::ReadOnly))
                throw std::logic_error("file is empty or doesn't exist");
            while(!file.atEnd()){
                auto data(file.readLine());
                if(data[0] == 'v' && data[1] == ' ') PushVertex(vertex, data);
                else if(data[0] == 'f'&& data[1] == ' ') PushFace(face, data);
            }
            if (*std::max_element(face.begin(), face.end()) >= vertex.size() /3)
                throw std::logic_error("nice SEGA you got there");
    }

    void ObjParser::PushVertex(QVector<double> &vertex, QByteArray &data)
    {
        QStringList ver = QString(data).split(' ');
        ver.erase(ver.cbegin());
        for(const auto& s : ver){
            vertex.push_back(s.toDouble());
        }
    }

    void ObjParser::PushFace(QVector<int> &face, QByteArray &data)
    {
        QStringList fac = QString(data).split(' ', Qt::SkipEmptyParts);
        for(auto& s: fac){
            if(s[0].isDigit()){
                s.remove(s.indexOf('/'), s.size() -1);
                face.push_back(s.toInt());
            }
        }
        face.push_back(fac[0].toInt());
    }


}
