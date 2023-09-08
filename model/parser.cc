#include "parser.h"
#include <fstream>
namespace s21{
     void s21::ObjParser::ParseFile()
    {
         tmp_vertex_.clear();
         tmp_face_.clear();
         QFile file(filename_);
         if(!file.exists() || !file.open(QIODevice::ReadOnly)){
             throw std::logic_error("file is empty or doesn't exist");
             file.close();

         }
            while(!file.atEnd()){
                auto data(file.readLine());
                if(data[0] == 'v' && data[1] == ' ')
                    PushVertex(data);
                else if(data[0] == 'f'&& data[1] == ' ')
                    PushFace(data);

            }


            // if (*(std::max_element(face.begin(), face.end())) > (vertex.size() /3 -1) ){
            //     throw std::logic_error("nice SEGA you got there");
            //     file.close();
            // }
            // ChangeFilename(filename, vertex, face);
            file.close();
            emit ParseOver(true);

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
            tmp_vertex_.push_back(std::stof(cstr));
            cstr+=size;
            size = 0;
            ++sizeline_counter;
        }
        // if(sizeline_counter != 3) throw std::invalid_argument("Broken Vertexes");

    }

    void ObjParser::PushFace(QByteArray &data)
    {
        int i = 0;
        auto cstr = data.data();
        int n = data.size();
        while(i<n && !(std::isdigit(*cstr))){
            ++cstr; i++;
        }
        // if(*cstr == '\n') throw std::invalid_argument("Broken Face");
        unsigned int first = std::stoi(cstr) -1;
        tmp_face_.push_back(first);
        while(i<n && !std::isspace(*cstr)){
            ++cstr; i++;
        }
        while(i<n && !(std::isdigit(*cstr))){
            ++cstr; i++;
        }
        while(i < n){
            tmp_face_.push_back(std::stoi(cstr) - 1);
            tmp_face_.push_back(std::stoi(cstr) - 1);
            while(i<n &&!std::isspace(*cstr)){
                ++cstr; i++;
            }
            while(i<n && !(std::isdigit(*cstr))){
                ++cstr; i++;
            }
        }
        tmp_face_.push_back(first);
    }

    // void ObjParser::ChangeFilename(QString &filename, QVector<float> &vertex, QVector<unsigned int> &face)  const
    // {
    //     filename =  filename.mid(filename.lastIndexOf("/") + 1).chopped(4) + "\n" +
    //             "Vertexes: " + QString::number(vertex.size() / 3) +
    //             " Edges: " + QString::number(face.size()/2);
    // }



}
