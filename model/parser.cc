#include "parser.h"
#include <fstream>
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
                if(data[0] == 'v' && data[1] == ' ')
                    PushVertex(data);
                else if(data[0] == 'f'&& data[1] == ' ')
                    PushFace(data);

            }
            if (*(std::max_element(face_.begin(), face_.end())) > (vertex_.size() /3 -1) )
                throw std::logic_error("nice SEGA you got there");
            ChangeFilename(filename);

}
    void ObjParser::PushVertex(QByteArray &data)
    {
        auto cstr = data.data();
        int size = 0, sizeline_counter = 0;
        while(*cstr != EOF && *cstr != '\n'){
            while(!(std::isdigit(*cstr) || *cstr == '.' || *cstr == '-' || *cstr == '+'))
                ++cstr;
            while(std::isdigit(*(cstr + size)) || *(cstr + size) == '.' || *(cstr + size) == '-' || *(cstr + size) == '+')
                ++size;
            vertex_.push_back(std::stof(cstr));
            cstr+=size;
            size = 0;
            ++sizeline_counter;
        }
        if(sizeline_counter != 3) throw std::invalid_argument("Broken Vertexes");

    }

    void ObjParser::PushFace(QByteArray &data)
    {
        int i = 0;
        auto cstr = data.data();
        int n = data.size();
        while(i<n && !(std::isdigit(*cstr))){
            ++cstr; i++;
        }
        if(*cstr == '\n') throw std::invalid_argument("Broken Face");
        float first = std::stof(cstr) -1;
        face_.push_back(first);
        while(i<n && !std::isspace(*cstr)){
            ++cstr; i++;
        }
        while(i<n && !(std::isdigit(*cstr))){
            ++cstr; i++;
        }
        while(i < n){
            face_.push_back(std::stof(cstr) - 1);
            face_.push_back(std::stof(cstr) - 1);
            while(i<n &&!std::isspace(*cstr)){
                ++cstr; i++;
            }
            while(i<n && !(std::isdigit(*cstr))){
                ++cstr; i++;
            }
        }
        face_.push_back(first);
    }

    void ObjParser::ChangeFilename(QString &filename)  const
    {
        filename =  filename.mid(filename.lastIndexOf("/") + 1).chopped(4) + "\n" +
                "Vertexes: " + QString::number(vertex_.size() / 3) +
                " Edges: " + QString::number(face_.size()/2);
    }


}
