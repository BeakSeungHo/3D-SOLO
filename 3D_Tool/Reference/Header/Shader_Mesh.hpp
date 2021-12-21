#include "Shader_Base.hpp"

float	g_TimeAccY;
float	g_fCrossY;

vector	g_vCamPos;

texture g_NormalTexture;

sampler NormalSampler = sampler_state
{
	texture = g_NormalTexture;
};

struct VS_IN
{
	vector		vPosition	: POSITION;	
	vector		vNormal		: NORMAL;
	float2		vTexUV		: TEXCOORD0;

};

struct VS_OUT
{
	vector		vPosition	: POSITION;
	vector		vNormal		: NORMAL;
	float2		vTexUV		: TEXCOORD0;
	vector		vProjPos	: TEXCOORD1;
	float3		vCamDir		: TEXCOORD2;
};

// 버텍스 쉐이더 함수
VS_OUT		VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix		matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);
	Out.vNormal = normalize(mul(vector(In.vNormal.xyz, 0.f), g_matWorld));
	Out.vTexUV = In.vTexUV;
	Out.vProjPos = Out.vPosition;

	return Out;
}

VS_OUT		VS_CROSS(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix		matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	In.vPosition.y = g_fCrossY;
	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);
	Out.vNormal = normalize(mul(vector(In.vNormal.xyz, 0.f), g_matWorld));
	Out.vTexUV = In.vTexUV;
	Out.vProjPos = Out.vPosition;

	return Out;
}

VS_OUT		VS_RIMLIGHT(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix		matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);
	Out.vNormal = normalize(mul(vector(In.vNormal.xyz, 0.f), g_matWorld));
	
	vector WorldPos = mul(vector(In.vPosition.xyz, 1.f), g_matWorld);

	Out.vCamDir = normalize(g_vCamPos - WorldPos);
	Out.vTexUV = In.vTexUV;
	Out.vProjPos = Out.vPosition;

	return Out;
}

struct PS_IN // 픽셀 쉐이더 구조체에서 POSITION이란 Semantic은 사용할 수 없다.
{
	vector			vNormal : NORMAL;
	float2			vTexUV	: TEXCOORD0;
	vector			vProjPos : TEXCOORD1;
	float3			vCamDir : TEXCOORD2;
};

struct PS_OUT
{
	vector			vColor : COLOR0;
	vector			vNormal : COLOR1;
	vector			vDepth : COLOR2;
};

PS_OUT		PS_MAIN(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;
	
	Out.vColor = tex2D(BaseSampler, In.vTexUV);

	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);

	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w,	// z나누기를 수행하여 0~1사이의 투영 z값을 만들고, 이를 텍스쳐 uv좌표로 판단
						In.vProjPos.w * 0.001f,			// 뷰스페이스 상태의 z값을 텍스쳐의 uv로 변환
						0.f,
						0.f);
	
	return Out;
}

PS_OUT		PS_ALPHA(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);
		
	return Out;
}

PS_OUT		PS_CONVEYOR(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	In.vTexUV.y -= g_TimeAccY;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);
	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);//tex2D(NormalSampler, In.vTexUV);
	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w,	// z나누기를 수행하여 0~1사이의 투영 z값을 만들고, 이를 텍스쳐 uv좌표로 판단
		In.vProjPos.w * 0.001f,			// 뷰스페이스 상태의 z값을 텍스쳐의 uv로 변환
		0.f,
		0.f);

	return Out;
}

PS_OUT		PS_CONVEYORCORNER(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);
	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);//tex2D(NormalSampler, In.vTexUV);
	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w,	// z나누기를 수행하여 0~1사이의 투영 z값을 만들고, 이를 텍스쳐 uv좌표로 판단
		In.vProjPos.w * 0.001f,			// 뷰스페이스 상태의 z값을 텍스쳐의 uv로 변환
		0.f,
		0.f);

	return Out;
}

PS_OUT		PS_GLASS(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);
	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);
	Out.vColor.a = 0.3f;
	//float fRim = smoothstep(1.0f - 0.7f, 1.0f, 1 - max(0, dot(In.vNormal, In.vCamDir)));

	//vector	vRimColor = vector(1.f, 204.f / 255.f, 0.f, 1.f);

	//Out.vColor = Out.vColor + fRim;

	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w,	// z나누기를 수행하여 0~1사이의 투영 z값을 만들고, 이를 텍스쳐 uv좌표로 판단
		In.vProjPos.w * 0.001f,			// 뷰스페이스 상태의 z값을 텍스쳐의 uv로 변환
		0.f,
		0.f);

	return Out;
}

technique Default_Device
{
	pass	// 0
	{
		vertexshader = compile vs_3_0 VS_MAIN();		
		pixelshader  = compile ps_3_0 PS_MAIN();	
	}


	pass AlphaTesting	// 1
	{
		alphatestenable = true;
		alphafunc = greater;
		alpharef = 0xc0;
		cullmode = none;

		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_ALPHA();
	}

	pass Cross	// 2
	{
		vertexshader = compile vs_3_0 VS_CROSS();
		pixelshader = compile ps_3_0 PS_MAIN();
	}

	pass Conveyor	// 3
	{
		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_CONVEYOR();
	}

	pass ConveyorCorner	// 4
	{
		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_CONVEYORCORNER();
	}
	
	pass	GLASS// 5
	{
		alphablendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_GLASS();
	}
};