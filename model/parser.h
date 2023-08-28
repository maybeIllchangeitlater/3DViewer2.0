#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H
#include <QDir>
namespace s21{
    class ObjParser{
//        Q_OBJECT
    public:
        void ParseFile(QString& filename, QVector<double>& vertex, QVector<int>& face);
    private:
        void PushVertex(QVector<double>& vertex, QByteArray& data);
        void PushFace(QVector<int> &face, QByteArray& data);
        int StoFace(QByteArray& data);
    };
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_PARSER_H
