#include "Shader_Base.hpp"

float		g_fDetail;
float		g_fAlpha;

struct VS_IN
{
	vector		vPosition	: POSITION;	
	vector		vNormal		: NORMAL;
	float2		vTexUV		: TEXCOORD0;

};

struct VS_OUT
{
	vector		vPosition	: POSITION;
	vector		vNormal : NORMAL;
	float2		vTexUV		: TEXCOORD0;
	vector		vWorldPos	: TEXCOORD1;
	vector		vProjPos	: TEXCOORD2;

};

// 버텍스 쉐이더 함수
VS_OUT		VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix		matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);
	
	vector		vWorldPos = mul(vector(In.vPosition.xyz, 1.f), g_matWorld);
	Out.vNormal = normalize(mul(vector(In.vNormal.xyz, 0.f), g_matWorld));	
	Out.vTexUV = In.vTexUV;
	Out.vWorldPos = vWorldPos;

	Out.vProjPos = Out.vPosition;

	return Out;
}

struct PS_IN // 픽셀 쉐이더 구조체에서 POSITION이란 Semantic은 사용할 수 없다.
{
	
	vector			vNormal		: NORMAL;
	float2			vTexUV		: TEXCOORD0;
	vector			vWorldPos	: TEXCOORD1;
	vector			vProjPos	: TEXCOORD2;
};

struct PS_OUT
{
	vector			vColor	: COLOR0;
	vector			vNormal : COLOR1;
	vector			vDepth	: COLOR2;
};

PS_OUT		PS_MAIN(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;
	
	vector vColor   = tex2D(BaseSampler, In.vTexUV * g_fDetail);

	Out.vColor = vColor;
	Out.vColor.a = 1.f;

	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);

	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w, // z나누기를 수행하여 0~1사이의 투영 z값을 만들고, 이를 텍스쳐 uv좌표로 판단
						In.vProjPos.w * 0.001f,  // 뷰스페이스 상태의 z값을 텍스쳐의 uv로 변환
						0.f,	
						0.f);


	return Out;
}

PS_OUT		PS_ALPHA(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	vector vColor = tex2D(BaseSampler, In.vTexUV * g_fDetail);

	Out.vColor = vColor;
	Out.vColor.a = g_fAlpha;

	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);

	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w, // z나누기를 수행하여 0~1사이의 투영 z값을 만들고, 이를 텍스쳐 uv좌표로 판단
		In.vProjPos.w * 0.001f,  // 뷰스페이스 상태의 z값을 텍스쳐의 uv로 변환
		0.f,
		0.f);


	return Out;
}

technique Default_Device
{
	pass
	{
		vertexshader = compile vs_3_0 VS_MAIN();		
		pixelshader  = compile ps_3_0 PS_MAIN();	
	}

	pass Alpha
	{
		alphablendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_ALPHA();
	}
};