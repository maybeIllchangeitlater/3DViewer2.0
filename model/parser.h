#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#include <QDir>
#include <cctype>
namespace s21{
    class ObjParser {
    public:
        void ParseFile(QString &filename, QVector<float>& vertex, QVector<unsigned int> &face) const;
    private:
        void PushVertex(QByteArray& data, QVector<float>& vertex) const;
        void PushFace(QByteArray& data, QVector<unsigned int> &face) const;
        void ChangeFilename(QString& filename, QVector<float> &vertex, QVector<unsigned int> &face) const;
    };
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
