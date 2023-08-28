#include "parser.h"
namespace s21{
     void s21::ObjParser::ParseFile(QString &filename)
    {
         vertex_.clear();
         face_.clear();
            QFile file(filename);
            if(!file.exists() || !file.open(QIODevice::ReadOnly))
                throw std::logic_error("file is empty or doesn't exist");
            while(!file.atEnd()){
                auto data(file.readLine());
                if(data[0] == 'v' && data[1] == ' ') PushVertex(data);
                else if(data[0] == 'f'&& data[1] == ' ') PushFace(data);
            }
            if (*(std::max_element(face_.begin(), face_.end())) > (vertex_.size() /3 -1) )
                throw std::logic_error("nice SEGA you got there");
            ChangeFilename(filename);
    }

    void ObjParser::PushVertex(QByteArray &data)
    {
        QStringList ver = QString(data).split(' ', Qt::SkipEmptyParts);
        ver.erase(ver.cbegin());
        for(const auto& s : ver){
            vertex_.push_back(s.toDouble());
        }
    }

    void ObjParser::PushFace(QByteArray &data)
    {
        QStringList fac = QString(data).split(' ', Qt::SkipEmptyParts);
        for(auto& s: fac){
            if(s[0].isDigit()){
                s.remove(s.indexOf('/'), s.size() -1);
                face_.push_back(s.toInt() -1);
                if(s != fac[1])
                    face_.push_back(s.toInt() - 1);
            }
        }
        face_.push_back(fac[1].toInt() - 1);
    }

    void ObjParser::ChangeFilename(QString &filename)  const
    {
        filename =  filename.mid(filename.lastIndexOf("/") + 1).chopped(4) + "\n" +
                "Vertexes: " + QString::number(vertex_.size() / 3) +
                " Edges: " + QString::number(face_.size()/2);
    }


}
