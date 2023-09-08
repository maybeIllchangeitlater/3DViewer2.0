#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#include <QDir>
#include <cctype>
namespace s21{
    
    class ObjParser : public QObject{

        Q_OBJECT

    public:
        void ParseFile();

        constexpr inline const QVector<float>& GetTmpVertexConstRef() const{return tmp_vertex_;}
        constexpr inline const QVector<unsigned int>& GetFaceConstRef() const{return tmp_face_;}

        void SetFilename(QString filename){
            filename_ = filename;
        }
    
    signals:
        void ParseOver(bool);

    private:
        void PushVertex(QByteArray& data);
        void PushFace(QByteArray& data);
        // void ChangeFilename(QString& filename, QVector<float> &vertex, QVector<unsigned int> &face) const;

        QVector<float> tmp_vertex_;
        QVector<unsigned int> tmp_face_;

        QString filename_;
    };
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
