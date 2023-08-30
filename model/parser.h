#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H
#include <QDir>
#include <tuple>
#include <cctype>
namespace s21{
    class ObjParser{
    public:
        void ParseFile(QString &filename);
        constexpr inline const QVector<float>& GetVertexConstRef() const{return vertex_;}
        constexpr inline const QVector<int>& GetFaceConstRef() const{return face_;}
    private:
        void PushVertex(QByteArray& data);
        void PushFace(QByteArray& data);
        void ChangeFilename(QString& filename) const;
        QVector<float> vertex_;
        QVector<int> face_;
    };
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_PARSER_H
