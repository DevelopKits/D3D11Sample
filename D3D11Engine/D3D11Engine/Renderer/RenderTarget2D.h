#pragma once
#include "HpD3D9Type.h"

class RenderTarget2D
{
public:
	RenderTarget2D(int Width, int Height, DXGI_FORMAT Format, bool bDepth =false);
	~RenderTarget2D();
	
	ID3D11RenderTargetView* GetRTView(){ return mRTV; }
	ID3D11DepthStencilView* GetDSView(){ return mDSV; }
	//����ͬʱ��RT�󶨵����ߣ��ְ�RT��ͼ�󶨵���һ��RT�ϣ����о���
	ID3D11ShaderResourceView* GetSRView();

	void Begin();

	void End();
	void SetBackBufferRenderTarget();

	void Save(const char* fileName);

private:
	ID3D11Texture2D* mTexture2D;
	ID3D11RenderTargetView* mRTV;
	ID3D11Texture2D* mTextureShader2D;

	ID3D11ShaderResourceView* mSRV;
	D3D11_VIEWPORT mViewport;

	ID3D11DepthStencilView* mDSV;

	ID3D11RenderTargetView	*m_renderTargetView;		//��Ⱦ������ͼ
	ID3D11DepthStencilView	*m_depthStencilView;		//���/ģ����ͼ
};

