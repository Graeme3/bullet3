#ifndef OPENGL_GUI_HELPER_H
#define OPENGL_GUI_HELPER_H
#include "../CommonInterfaces/CommonGUIHelperInterface.h"

class btCollisionShape;
class btTransform;
#include "LinearMath/btAlignedObjectArray.h"

struct OpenGLGuiHelper : public GUIHelperInterface
{
	struct OpenGLGuiHelperInternalData* m_data;

	OpenGLGuiHelper(struct CommonGraphicsApp* glApp, bool useOpenGL2);

	virtual ~OpenGLGuiHelper();

	virtual struct CommonRenderInterface* getRenderInterface();
	virtual const struct CommonRenderInterface* getRenderInterface() const;

	virtual void createRigidBodyGraphicsObject(btRigidBody* body, const btVector3& color);

	virtual void createCollisionObjectGraphicsObject(btCollisionObject* body, const btVector3& color);

	virtual int	registerTexture(const unsigned char* texels, int width, int height);
	virtual int registerGraphicsShape(const float* vertices, int numvertices, const int* indices, int numIndices,int primitiveType, int textureId);
	virtual int registerGraphicsInstance(int shapeIndex, const float* position, const float* quaternion, const float* color, const float* scaling);
	virtual void removeAllGraphicsInstances();
	virtual void removeGraphicsInstance(int graphicsUid);
	virtual void changeRGBAColor(int instanceUid, const double rgbaColor[4]);
	
	virtual void createCollisionShapeGraphicsObject(btCollisionShape* collisionShape);

	virtual void syncPhysicsToGraphics(const btDiscreteDynamicsWorld* rbWorld);

	
	virtual void render(const btDiscreteDynamicsWorld* rbWorld);

	virtual void createPhysicsDebugDrawer(btDiscreteDynamicsWorld* rbWorld);

	virtual struct Common2dCanvasInterface*	get2dCanvasInterface();

	virtual CommonParameterInterface* getParameterInterface();

	virtual struct CommonGraphicsApp* getAppInterface();

	virtual void setUpAxis(int axis);
	
    
	virtual void resetCamera(float camDist, float pitch, float yaw, float camPosX,float camPosY, float camPosZ);
	virtual bool getCameraInfo(int* width, int* height, float viewMatrix[16], float projectionMatrix[16], float camUp[3], float camForward[3],float hor[3], float vert[3] ) const;

	virtual void copyCameraImageData(const float viewMatrix[16], const float projectionMatrix[16], 
                                  unsigned char* pixelsRGBA, int rgbaBufferSizeInPixels, 
                                  float* depthBuffer, int depthBufferSizeInPixels, 
                                  int* segmentationMaskBuffer, int segmentationMaskBufferSizeInPixels,
                                  int startPixelIndex, int destinationWidth, 
                                  int destinationHeight, int* numPixelsCopied);

	virtual void autogenerateGraphicsObjects(btDiscreteDynamicsWorld* rbWorld) ;
    
    virtual void drawText3D( const char* txt, float posX, float posY, float posZ, float size);

	virtual int		addUserDebugText3D( const char* txt, const double positionXYZ[3], const double	textColorRGB[3], double size, double lifeTime)
	{
		return -1;
	}
	virtual int		addUserDebugLine(const double	debugLineFromXYZ[3], const double	debugLineToXYZ[3], const double	debugLineColorRGB[3], double lineWidth, double lifeTime )
	{
		return -1;
	}
	virtual int		addUserDebugParameter(const char* txt, double	rangeMin, double	rangeMax, double startValue)
	{
		return -1;
	}

	virtual void	removeUserDebugItem( int debugItemUniqueId)
	{
	}
	virtual void	removeAllUserDebugItems( )
	{
	}


	void renderInternalGl2(int  pass, const btDiscreteDynamicsWorld* dynamicsWorld);

	void setVRMode(bool vrMode);

	void setVisualizerFlag(int flag, int enable);

	virtual void	setVisualizerFlagCallback(VisualizerFlagCallback callback);

	virtual void	dumpFramesToVideo(const char* mp4FileName);

	int createCheckeredTexture(int r,int g, int b);
};

#endif //OPENGL_GUI_HELPER_H

