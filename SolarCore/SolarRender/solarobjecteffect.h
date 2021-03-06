#ifndef SOLAROBJECTEFFECT_H
#define SOLAROBJECTEFFECT_H

#include <Qt3DRender/QEffect>
#include <Qt3DRender/QRenderPass>
#include <SolarCore/SolarRender/solarlight.h>

namespace SolarSystem {

    //represents any solid solar system body effect
    class SolarObjectEffect : public Qt3DRender::QEffect
    {
        Q_OBJECT

    public:
        SolarObjectEffect(Qt3DCore::QNode* parent = nullptr);

        //get/set light
        SolarLight* light() const;
        void setLight(SolarLight* light);

        //get/set shaders source
        QString vertexShaderSource() const;
        QString fragmentShaderSource() const;
        void setVertexShaderSource(const QString& source);
        void setFragmentShaderSource(const QString& source);

        //init effect
        void initialization();

    private:

        //standard gl pass
        Qt3DRender::QRenderPass* glPass;

        //light
        SolarLight* lightObject = nullptr;

        //shaders source
        QString vertexShaderGL;
        QString fragShaderGL;
    };
}

#endif // SOLAROBJECTEFFECT_H
