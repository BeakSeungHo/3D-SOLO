xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Mon May 15 16:57:27 2017

// Start of Templates

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template FVFData {
 <b6e70a0e-8ef9-4e83-94ad-ecc8b0c04897>
 DWORD dwFVF;
 DWORD nDWords;
 array DWORD data[nDWords];
}

template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template FrameTransformMatrix {
 <F6F23F41-7686-11cf-8F52-0040333594A3>
 Matrix4x4 frameMatrix;
}

template Frame {
 <3D82AB46-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template FloatKeys {
 <10DD46A9-775B-11cf-8F52-0040333594A3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <F406B180-7B3B-11cf-8F52-0040333594A3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10DD46A8-775B-11cf-8F52-0040333594A3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}

template AnimationOptions {
 <E2BF56C0-840F-11cf-8F52-0040333594A3>
 DWORD openclosed;
 DWORD positionquality;
}

template Animation {
 <3D82AB4F-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template AnimationSet {
 <3D82AB50-62DA-11cf-AB39-0020AF71E433>
 [Animation]
}

template XSkinMeshHeader {
 <3CF169CE-FF7C-44ab-93C0-F78F62D172E2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template SkinWeights {
 <6F0D123B-BAD2-4167-A0D0-80224F25FABB>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}

template AnimTicksPerSecond {
 <9E415A43-7BA6-4a73-8743-B73D47E88476>
 DWORD AnimTicksPerSecond;
}

AnimTicksPerSecond {
 30;
}

// Start of Frames

Frame SceneRoot {
  FrameTransformMatrix {
   1.000000, 0.000000, 0.000000, 0.000000,
   0.000000, 1.000000, 0.000000, 0.000000,
   0.000000, 0.000000, 1.000000, 0.000000,
   0.000000, 0.000000, 0.000000, 1.000000;;
  }

   Frame sm_cabaret {
      FrameTransformMatrix {
       1.000000, 0.000000, -0.000000, 0.000000,
       0.000000, -0.000000, -1.000000, 0.000000,
       0.000000, 1.000000, -0.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

   }

   Frame Body {
      FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

      Mesh skinnedMesh {
       122;
       -25.690292; 4.383850; 16.549297;,
       -20.840151; 4.261422; 17.850294;,
       -21.463146; 2.072105; 16.505236;,
       23.002335; 3.738516; 18.729527;,
       26.682030; 1.242020; 16.633690;,
       28.016748; 3.590247; 17.328239;,
       21.964685; 1.242020; 18.011082;,
       -20.762598; 1.242020; 18.011082;,
       -21.828627; 3.738516; 18.729527;,
       -25.479942; 1.242020; 16.633690;,
       -26.843040; 3.864440; 17.328239;,
       22.014133; 4.261422; 17.850294;,
       26.864277; 4.109657; 16.549297;,
       22.664896; 2.072105; 16.505236;,
       26.864277; 4.383850; -19.064695;,
       23.002335; 3.738516; -21.249193;,
       22.014133; 4.261422; -20.365692;,
       28.016748; 3.864440; -19.847904;,
       28.784121; 4.261422; -15.777961;,
       30.084591; 3.738516; -16.449850;,
       -21.828627; 3.738516; -21.249193;,
       -25.479942; 1.242020; -18.714258;,
       -26.843040; 3.864440; -19.847904;,
       -20.762598; 1.242020; -20.091650;,
       23.002335; 3.738516; -21.249193;,
       21.964685; 1.242020; -20.091650;,
       26.682030; 1.242020; -18.714258;,
       28.016748; 3.864440; -19.847904;,
       -20.840151; 4.261422; 17.850294;,
       22.014133; 4.261422; 17.850294;,
       -21.463146; 2.072105; 16.505236;,
       22.664896; 2.072105; 16.505236;,
       26.864277; 4.383850; -19.064695;,
       22.664896; 2.072105; -18.591036;,
       27.202822; 2.072105; -15.202485;,
       28.784121; 4.261422; -15.777961;,
       28.784121; 4.261422; 13.262563;,
       27.202822; 2.072105; 13.116687;,
       26.864277; 4.109657; 16.549297;,
       -26.001074; 2.072105; 13.116687;,
       -25.690292; 4.383850; 16.549297;,
       -27.610138; 4.261422; 13.262563;,
       -26.001074; 2.072105; -15.202485;,
       -27.610138; 4.261422; -15.777961;,
       -25.690292; 4.383850; -19.064695;,
       -21.463146; 2.072105; -18.591036;,
       -20.840151; 4.261422; -20.365692;,
       22.014133; 4.261422; -20.365692;,
       -26.843040; 3.864440; 17.328239;,
       -27.610138; 4.261422; 13.262563;,
       -28.910883; 3.738516; 13.930184;,
       -25.690292; 4.383850; 16.549297;,
       -21.828627; 3.738516; 18.729527;,
       -20.840151; 4.261422; 17.850294;,
       22.014133; 4.261422; 17.850294;,
       23.002335; 3.738516; 18.729527;,
       26.864277; 4.109657; 16.549297;,
       28.016748; 3.590247; 17.328239;,
       30.084591; 3.738516; 13.930184;,
       28.784121; 4.261422; 13.262563;,
       22.014133; 4.261422; -20.365692;,
       23.002335; 3.738516; -21.249193;,
       -20.840151; 4.261422; -20.365692;,
       -21.828627; 3.738516; -21.249193;,
       -27.610138; 4.261422; -15.777961;,
       -28.910883; 3.738516; -16.449850;,
       -27.610138; 4.261422; 13.262563;,
       -28.910883; 3.738516; 13.930184;,
       28.784121; 4.261422; 13.262563;,
       30.084591; 3.738516; 13.930184;,
       28.784121; 4.261422; -15.777961;,
       30.084591; 3.738516; -16.449850;,
       30.084591; 3.738516; 13.930184;,
       28.016748; 3.590247; 17.328239;,
       28.714607; 1.242020; 13.436946;,
       26.682030; 1.242020; 16.633690;,
       -28.910883; 3.738516; 13.930184;,
       -27.512522; 1.242020; 13.436946;,
       -26.843040; 3.864440; 17.328239;,
       -25.479942; 1.242020; 16.633690;,
       28.714607; 1.242020; -15.517514;,
       26.682030; 1.242020; -18.714258;,
       30.084591; 3.738516; -16.449850;,
       28.016748; 3.864440; -19.847904;,
       -27.512522; 1.242020; -15.517514;,
       -28.910883; 3.738516; -16.449850;,
       -25.479942; 1.242020; -18.714258;,
       -26.843040; 3.864440; -19.847904;,
       30.084591; 3.738516; -16.449850;,
       30.084591; 3.738516; 13.930184;,
       28.714607; 1.242020; -15.517514;,
       28.714607; 1.242020; 13.436946;,
       -27.512522; 1.242020; 13.436946;,
       -28.910883; 3.738516; 13.930184;,
       -27.512522; 1.242020; -15.517514;,
       -28.910883; 3.738516; -16.449850;,
       -20.840151; 4.261422; -20.365692;,
       -21.828627; 3.738516; -21.249193;,
       -25.690292; 4.383850; -19.064695;,
       -26.843040; 3.864440; -19.847904;,
       -27.610138; 4.261422; -15.777961;,
       -28.910883; 3.738516; -16.449850;,
       -26.001074; 2.072105; 13.116687;,
       -21.463146; 2.072105; 16.505236;,
       -26.001074; 2.072105; -15.202485;,
       -21.463146; 2.072105; -18.591036;,
       22.664896; 2.072105; 16.505236;,
       22.664896; 2.072105; -18.591036;,
       27.202822; 2.072105; 13.116687;,
       27.202822; 2.072105; -15.202485;,
       28.714607; 1.242020; 13.436946;,
       26.682030; 1.242020; 16.633690;,
       28.714607; 1.242020; -15.517514;,
       26.682030; 1.242020; -18.714258;,
       21.964685; 1.242020; 18.011082;,
       21.964685; 1.242020; -20.091650;,
       -20.762598; 1.242020; 18.011082;,
       -20.762598; 1.242020; -20.091650;,
       -25.479942; 1.242020; 16.633690;,
       -25.479942; 1.242020; -18.714258;,
       -27.512522; 1.242020; 13.436946;,
       -27.512522; 1.242020; -15.517514;;
       84;
       3;0, 1, 2;,
       3;3, 4, 5;,
       3;6, 4, 3;,
       3;6, 3, 7;,
       3;7, 3, 8;,
       3;7, 8, 9;,
       3;9, 8, 10;,
       3;11, 12, 13;,
       3;14, 15, 16;,
       3;17, 15, 14;,
       3;18, 17, 14;,
       3;19, 17, 18;,
       3;20, 21, 22;,
       3;23, 21, 20;,
       3;20, 24, 23;,
       3;23, 24, 25;,
       3;25, 24, 26;,
       3;26, 24, 27;,
       3;28, 29, 30;,
       3;30, 29, 31;,
       3;32, 33, 34;,
       3;35, 32, 34;,
       3;35, 34, 36;,
       3;36, 34, 37;,
       3;36, 37, 38;,
       3;38, 37, 31;,
       3;30, 39, 40;,
       3;41, 40, 39;,
       3;42, 41, 39;,
       3;43, 41, 42;,
       3;44, 43, 42;,
       3;42, 45, 44;,
       3;46, 44, 45;,
       3;46, 45, 47;,
       3;47, 45, 33;,
       3;47, 33, 32;,
       3;48, 49, 50;,
       3;51, 49, 48;,
       3;52, 51, 48;,
       3;53, 51, 52;,
       3;52, 54, 53;,
       3;55, 54, 52;,
       3;54, 55, 56;,
       3;56, 55, 57;,
       3;57, 58, 56;,
       3;56, 58, 59;,
       3;60, 61, 62;,
       3;62, 61, 63;,
       3;64, 65, 66;,
       3;66, 65, 67;,
       3;68, 69, 70;,
       3;70, 69, 71;,
       3;72, 73, 74;,
       3;74, 73, 75;,
       3;76, 77, 78;,
       3;78, 77, 79;,
       3;80, 81, 82;,
       3;82, 81, 83;,
       3;84, 85, 86;,
       3;86, 85, 87;,
       3;88, 89, 90;,
       3;90, 89, 91;,
       3;92, 93, 94;,
       3;94, 93, 95;,
       3;96, 97, 98;,
       3;98, 97, 99;,
       3;98, 99, 100;,
       3;100, 99, 101;,
       3;102, 103, 104;,
       3;104, 103, 105;,
       3;103, 106, 105;,
       3;105, 106, 107;,
       3;108, 107, 106;,
       3;109, 107, 108;,
       3;110, 111, 112;,
       3;112, 111, 113;,
       3;111, 114, 113;,
       3;113, 114, 115;,
       3;114, 116, 115;,
       3;115, 116, 117;,
       3;116, 118, 117;,
       3;117, 118, 119;,
       3;118, 120, 119;,
       3;121, 119, 120;;

      MeshNormals {
       122;
       0.241156; 0.457281; -0.856001;,
       0.241156; 0.457281; -0.856001;,
       0.241156; 0.457281; -0.856001;,
       0.125501; -0.332098; 0.934859;,
       0.248576; -0.381165; 0.890462;,
       0.236170; -0.396616; 0.887085;,
       0.131775; -0.324341; 0.936717;,
       -0.087659; -0.309881; 0.946726;,
       -0.174637; -0.341528; 0.923504;,
       -0.259595; -0.369398; 0.892276;,
       -0.258591; -0.370669; 0.892040;,
       -0.215977; 0.463709; -0.859260;,
       -0.215977; 0.463709; -0.859260;,
       -0.215977; 0.463709; -0.859260;,
       0.173325; 0.922145; -0.345841;,
       0.096745; 0.895007; -0.435433;,
       0.092302; 0.898730; -0.428679;,
       0.244192; 0.936646; -0.251126;,
       0.310318; 0.938713; -0.150071;,
       0.301793; 0.941697; -0.148755;,
       -0.164658; -0.470992; -0.866634;,
       -0.245059; -0.490646; -0.836189;,
       -0.246068; -0.489533; -0.836545;,
       -0.081987; -0.447835; -0.890349;,
       0.123761; -0.458623; -0.879971;,
       0.123265; -0.459152; -0.879764;,
       0.245356; -0.488569; -0.837318;,
       0.246329; -0.487486; -0.837663;,
       0.000000; 0.523472; -0.852043;,
       0.000000; 0.523472; -0.852043;,
       0.138357; 0.618106; -0.773823;,
       -0.195049; 0.680879; -0.705946;,
       -0.442095; 0.675351; 0.590299;,
       -0.204938; 0.677800; 0.706108;,
       -0.701925; 0.670100; 0.241387;,
       -0.763989; 0.608339; 0.215043;,
       -0.798781; 0.586015; -0.136147;,
       -0.669935; 0.672095; -0.315397;,
       -0.565229; 0.683706; -0.461585;,
       0.670360; 0.659581; -0.339957;,
       0.566061; 0.659104; -0.495134;,
       0.792073; 0.592049; -0.148655;,
       0.697579; 0.675027; 0.240254;,
       0.759422; 0.614397; 0.213999;,
       0.440144; 0.678277; 0.588399;,
       0.153040; 0.669621; 0.726765;,
       0.113596; 0.605919; 0.787374;,
       -0.075777; 0.614202; 0.785502;,
       -0.244543; 0.936396; 0.251719;,
       -0.310611; 0.938587; 0.150251;,
       -0.302078; 0.941578; 0.148933;,
       -0.173693; 0.921712; 0.346810;,
       -0.048657; 0.878688; 0.474911;,
       -0.046426; 0.880623; 0.471538;,
       0.044670; 0.879883; 0.473087;,
       0.090988; 0.895484; 0.435694;,
       0.207748; 0.929930; 0.303433;,
       0.210476; 0.928010; 0.307404;,
       0.276606; 0.938397; 0.207124;,
       0.273660; 0.940104; 0.203259;,
       0.000000; 0.860569; -0.509334;,
       0.000000; 0.860569; -0.509334;,
       0.000000; 0.860569; -0.509334;,
       0.000000; 0.860569; -0.509334;,
       -0.372994; 0.927834; 0.000000;,
       -0.372994; 0.927834; 0.000000;,
       -0.372994; 0.927834; 0.000000;,
       -0.372994; 0.927834; 0.000000;,
       0.373062; 0.927807; 0.000000;,
       0.373062; 0.927807; 0.000000;,
       0.373062; 0.927807; 0.000000;,
       0.373062; 0.927807; 0.000000;,
       0.750404; -0.497724; 0.434931;,
       0.731167; -0.518119; 0.443789;,
       0.731167; -0.518119; 0.443789;,
       0.711297; -0.538066; 0.452262;,
       -0.730957; -0.500981; 0.463379;,
       -0.730347; -0.501588; 0.463684;,
       -0.730347; -0.501588; 0.463684;,
       -0.729737; -0.502195; 0.463987;,
       0.703178; -0.552850; -0.447100;,
       0.703201; -0.552300; -0.447742;,
       0.703201; -0.552300; -0.447742;,
       0.703225; -0.551749; -0.448385;,
       -0.700068; -0.558364; -0.445123;,
       -0.700101; -0.557694; -0.445911;,
       -0.700101; -0.557694; -0.445911;,
       -0.700133; -0.557023; -0.446699;,
       0.876674; -0.481086; 0.000000;,
       0.876674; -0.481086; 0.000000;,
       0.876674; -0.481086; 0.000000;,
       0.876674; -0.481086; 0.000000;,
       -0.872458; -0.488689; 0.000000;,
       -0.872458; -0.488689; 0.000000;,
       -0.872458; -0.488689; 0.000000;,
       -0.872458; -0.488689; 0.000000;,
       -0.092297; 0.898739; -0.428661;,
       -0.096740; 0.895017; -0.435414;,
       -0.173305; 0.922158; -0.345818;,
       -0.244160; 0.936662; -0.251100;,
       -0.310273; 0.938732; -0.150044;,
       -0.301750; 0.941715; -0.148728;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;;
       84;
       3;0, 1, 2;,
       3;3, 4, 5;,
       3;6, 4, 3;,
       3;6, 3, 7;,
       3;7, 3, 8;,
       3;7, 8, 9;,
       3;9, 8, 10;,
       3;11, 12, 13;,
       3;14, 15, 16;,
       3;17, 15, 14;,
       3;18, 17, 14;,
       3;19, 17, 18;,
       3;20, 21, 22;,
       3;23, 21, 20;,
       3;20, 24, 23;,
       3;23, 24, 25;,
       3;25, 24, 26;,
       3;26, 24, 27;,
       3;28, 29, 30;,
       3;30, 29, 31;,
       3;32, 33, 34;,
       3;35, 32, 34;,
       3;35, 34, 36;,
       3;36, 34, 37;,
       3;36, 37, 38;,
       3;38, 37, 31;,
       3;30, 39, 40;,
       3;41, 40, 39;,
       3;42, 41, 39;,
       3;43, 41, 42;,
       3;44, 43, 42;,
       3;42, 45, 44;,
       3;46, 44, 45;,
       3;46, 45, 47;,
       3;47, 45, 33;,
       3;47, 33, 32;,
       3;48, 49, 50;,
       3;51, 49, 48;,
       3;52, 51, 48;,
       3;53, 51, 52;,
       3;52, 54, 53;,
       3;55, 54, 52;,
       3;54, 55, 56;,
       3;56, 55, 57;,
       3;57, 58, 56;,
       3;56, 58, 59;,
       3;60, 61, 62;,
       3;62, 61, 63;,
       3;64, 65, 66;,
       3;66, 65, 67;,
       3;68, 69, 70;,
       3;70, 69, 71;,
       3;72, 73, 74;,
       3;74, 73, 75;,
       3;76, 77, 78;,
       3;78, 77, 79;,
       3;80, 81, 82;,
       3;82, 81, 83;,
       3;84, 85, 86;,
       3;86, 85, 87;,
       3;88, 89, 90;,
       3;90, 89, 91;,
       3;92, 93, 94;,
       3;94, 93, 95;,
       3;96, 97, 98;,
       3;98, 97, 99;,
       3;98, 99, 100;,
       3;100, 99, 101;,
       3;102, 103, 104;,
       3;104, 103, 105;,
       3;103, 106, 105;,
       3;105, 106, 107;,
       3;108, 107, 106;,
       3;109, 107, 108;,
       3;110, 111, 112;,
       3;112, 111, 113;,
       3;111, 114, 113;,
       3;113, 114, 115;,
       3;114, 116, 115;,
       3;115, 116, 117;,
       3;116, 118, 117;,
       3;117, 118, 119;,
       3;118, 120, 119;,
       3;121, 119, 120;;
      }

      MeshTextureCoords {
       122;
       0.524414; 0.047272;,
       0.505859; 0.107361;,
       0.536621; 0.103821;,
       0.475586; 0.604980;,
       0.432861; 0.636719;,
       0.451416; 0.661133;,
       0.448242; 0.589844;,
       0.446289; 0.156494;,
       0.472900; 0.140747;,
       0.430420; 0.110229;,
       0.450684; 0.084045;,
       0.503906; 0.616699;,
       0.523438; 0.678223;,
       0.535156; 0.621582;,
       0.838867; 0.805176;,
       0.784180; 0.769043;,
       0.770020; 0.783203;,
       0.856934; 0.792969;,
       0.868164; 0.853027;,
       0.887695; 0.842773;,
       0.038208; 0.138306;,
       0.082458; 0.106812;,
       0.059387; 0.082397;,
       0.066711; 0.153564;,
       0.038208; 0.606934;,
       0.066956; 0.591797;,
       0.082703; 0.638672;,
       0.059357; 0.663086;,
       0.505859; 0.107361;,
       0.503906; 0.616699;,
       0.536621; 0.103821;,
       0.535156; 0.621582;,
       0.951172; 0.683105;,
       0.936035; 0.626465;,
       0.897461; 0.677246;,
       0.909668; 0.708008;,
       0.565430; 0.704590;,
       0.572266; 0.673340;,
       0.523438; 0.678223;,
       0.573242; 0.053223;,
       0.524414; 0.047272;,
       0.565918; 0.021545;,
       0.898438; 0.052582;,
       0.910645; 0.021790;,
       0.951660; 0.047028;,
       0.936523; 0.103333;,
       0.970215; 0.107178;,
       0.970215; 0.622559;,
       0.092957; 0.792480;,
       0.081238; 0.852539;,
       0.061646; 0.842285;,
       0.110718; 0.805176;,
       0.165161; 0.769531;,
       0.179565; 0.783203;,
       0.763184; 0.781738;,
       0.777344; 0.767578;,
       0.833008; 0.803711;,
       0.851563; 0.791016;,
       0.883301; 0.840820;,
       0.863770; 0.851563;,
       0.770020; 0.783203;,
       0.784180; 0.769043;,
       0.179565; 0.783203;,
       0.165161; 0.769043;,
       0.638184; 0.818848;,
       0.648438; 0.838379;,
       0.243896; 0.818848;,
       0.233765; 0.838379;,
       0.243896; 0.818848;,
       0.233276; 0.838379;,
       0.638184; 0.823242;,
       0.648438; 0.842773;,
       0.412598; 0.686523;,
       0.451416; 0.661133;,
       0.402100; 0.657227;,
       0.432861; 0.636719;,
       0.410645; 0.060608;,
       0.399902; 0.089722;,
       0.450684; 0.084045;,
       0.430420; 0.110229;,
       0.114319; 0.658691;,
       0.082703; 0.638672;,
       0.098755; 0.687500;,
       0.059357; 0.663086;,
       0.113770; 0.086975;,
       0.098572; 0.058105;,
       0.082458; 0.106812;,
       0.059387; 0.082397;,
       0.098755; 0.687500;,
       0.412598; 0.686523;,
       0.114319; 0.658691;,
       0.402100; 0.657227;,
       0.399902; 0.089722;,
       0.410645; 0.060608;,
       0.113770; 0.086975;,
       0.098572; 0.058105;,
       0.179565; 0.783203;,
       0.165161; 0.769043;,
       0.110657; 0.804688;,
       0.092896; 0.792480;,
       0.081726; 0.852051;,
       0.062103; 0.841797;,
       0.573242; 0.053223;,
       0.536621; 0.103821;,
       0.898438; 0.052582;,
       0.936523; 0.103333;,
       0.535156; 0.621582;,
       0.936035; 0.626465;,
       0.572266; 0.673340;,
       0.897461; 0.677246;,
       0.402100; 0.657227;,
       0.432861; 0.636719;,
       0.114319; 0.658691;,
       0.082703; 0.638672;,
       0.448242; 0.589844;,
       0.066956; 0.591797;,
       0.446289; 0.156494;,
       0.066711; 0.153564;,
       0.430420; 0.110229;,
       0.082458; 0.106812;,
       0.399902; 0.089722;,
       0.113770; 0.086975;;
      }

      FVFData {
       258;
       244;
       1063837696,
       1051820032,
       1063862272,
       1053589504,
       1064255488,
       1053360128,
       1063518208,
       1064411136,
       1063059456,
       1065082880,
       1063485440,
       1065328640,
       1063059456,
       1064222720,
       1063059456,
       1055932416,
       1063518208,
       1055547392,
       1063059456,
       1054220288,
       1063534592,
       1053720576,
       1064361984,
       1058848768,
       1064386560,
       1059733504,
       1064755200,
       1058963456,
       1062551552,
       1064738816,
       1062944768,
       1064034304,
       1062789120,
       1063854080,
       1062690816,
       1064951808,
       1061953536,
       1065091072,
       1062076416,
       1065328640,
       1063747584,
       1055547392,
       1064198144,
       1054220288,
       1063723008,
       1053720576,
       1064198144,
       1055932416,
       1063747584,
       1064411136,
       1064198144,
       1064222720,
       1064198144,
       1065082880,
       1063723008,
       1065328640,
       1054703616,
       1055154176,
       1054703616,
       1063854080,
       1055195136,
       1054924800,
       1055195136,
       1063976960,
       1062551552,
       1064738816,
       1062461440,
       1063976960,
       1061847040,
       1064804352,
       1061953536,
       1065091072,
       1056374784,
       1065091072,
       1056423936,
       1064804352,
       1055178752,
       1064738816,
       1056423936,
       1053278208,
       1055178752,
       1053384704,
       1056374784,
       1052688384,
       1061847040,
       1053278208,
       1061953536,
       1052688384,
       1062551552,
       1053384704,
       1062461440,
       1054924800,
       1062789120,
       1055154176,
       1062789120,
       1063854080,
       1054892032,
       1052966912,
       1056374784,
       1052688384,
       1056129024,
       1052213248,
       1055178752,
       1053384704,
       1054384128,
       1054793728,
       1054703616,
       1055154176,
       1054703616,
       1063854080,
       1054384128,
       1064034304,
       1055178752,
       1064738816,
       1054892032,
       1064951808,
       1056129024,
       1065328640,
       1056374784,
       1065091072,
       1063649280,
       1064230912,
       1063747584,
       1064411136,
       1063649280,
       1055907840,
       1063747584,
       1055547392,
       1061953536,
       1052688384,
       1062076416,
       1052213248,
       1056374784,
       1052688384,
       1056129024,
       1052213248,
       1056374784,
       1065091072,
       1056129024,
       1065328640,
       1061953536,
       1065091072,
       1062076416,
       1065328640,
       1052639232,
       1065328640,
       1053876224,
       1064951808,
       1052459008,
       1065074688,
       1053622272,
       1064706048,
       1052639232,
       1052213248,
       1052459008,
       1052721152,
       1053876224,
       1052966912,
       1053622272,
       1053466624,
       1028874240,
       1065074688,
       1015717888,
       1064706048,
       1026162688,
       1065328640,
       999809024,
       1064951808,
       1028874240,
       1052721152,
       1026162688,
       1052213248,
       1015717888,
       1053466624,
       999809024,
       1052966912,
       1065312256,
       1065328640,
       1065312256,
       1059799040,
       1064861696,
       1065156608,
       1064861696,
       1059889152,
       1064304640,
       1065238528,
       1064755200,
       1065328640,
       1064304640,
       1059962880,
       1064755200,
       1059799040,
       1062789120,
       1055154176,
       1062944768,
       1054793728,
       1062551552,
       1053384704,
       1062690816,
       1052966912,
       1061953536,
       1052688384,
       1062076416,
       1052213248,
       1056423936,
       1053278208,
       1055195136,
       1054924800,
       1061847040,
       1053278208,
       1062461440,
       1054924800,
       1055195136,
       1063976960,
       1062461440,
       1063976960,
       1056423936,
       1064804352,
       1061847040,
       1064804352,
       1052459008,
       1065074688,
       1053622272,
       1064706048,
       1028874240,
       1065074688,
       1015717888,
       1064706048,
       1054121984,
       1063845888,
       990019584,
       1063845888,
       1054121984,
       1055178752,
       990019584,
       1055178752,
       1053622272,
       1053466624,
       1015717888,
       1053466624,
       1052459008,
       1052721152,
       1028874240,
       1052721152;
      }

      MeshVertexColors {
       122;
       0; 1.000000; 1.000000; 1.000000; 1.000000;,
       1; 1.000000; 1.000000; 1.000000; 1.000000;,
       2; 1.000000; 1.000000; 1.000000; 1.000000;,
       3; 1.000000; 1.000000; 1.000000; 1.000000;,
       4; 1.000000; 1.000000; 1.000000; 1.000000;,
       5; 1.000000; 1.000000; 1.000000; 1.000000;,
       6; 1.000000; 1.000000; 1.000000; 1.000000;,
       7; 1.000000; 1.000000; 1.000000; 1.000000;,
       8; 1.000000; 1.000000; 1.000000; 1.000000;,
       9; 1.000000; 1.000000; 1.000000; 1.000000;,
       10; 1.000000; 1.000000; 1.000000; 1.000000;,
       11; 1.000000; 1.000000; 1.000000; 1.000000;,
       12; 1.000000; 1.000000; 1.000000; 1.000000;,
       13; 1.000000; 1.000000; 1.000000; 1.000000;,
       14; 1.000000; 1.000000; 1.000000; 1.000000;,
       15; 1.000000; 1.000000; 1.000000; 1.000000;,
       16; 1.000000; 1.000000; 1.000000; 1.000000;,
       17; 1.000000; 1.000000; 1.000000; 1.000000;,
       18; 1.000000; 1.000000; 1.000000; 1.000000;,
       19; 1.000000; 1.000000; 1.000000; 1.000000;,
       20; 1.000000; 1.000000; 1.000000; 1.000000;,
       21; 1.000000; 1.000000; 1.000000; 1.000000;,
       22; 1.000000; 1.000000; 1.000000; 1.000000;,
       23; 1.000000; 1.000000; 1.000000; 1.000000;,
       24; 1.000000; 1.000000; 1.000000; 1.000000;,
       25; 1.000000; 1.000000; 1.000000; 1.000000;,
       26; 1.000000; 1.000000; 1.000000; 1.000000;,
       27; 1.000000; 1.000000; 1.000000; 1.000000;,
       28; 1.000000; 1.000000; 1.000000; 1.000000;,
       29; 1.000000; 1.000000; 1.000000; 1.000000;,
       30; 1.000000; 1.000000; 1.000000; 1.000000;,
       31; 1.000000; 1.000000; 1.000000; 1.000000;,
       32; 1.000000; 1.000000; 1.000000; 1.000000;,
       33; 1.000000; 1.000000; 1.000000; 1.000000;,
       34; 1.000000; 1.000000; 1.000000; 1.000000;,
       35; 1.000000; 1.000000; 1.000000; 1.000000;,
       36; 1.000000; 1.000000; 1.000000; 1.000000;,
       37; 1.000000; 1.000000; 1.000000; 1.000000;,
       38; 1.000000; 1.000000; 1.000000; 1.000000;,
       39; 1.000000; 1.000000; 1.000000; 1.000000;,
       40; 1.000000; 1.000000; 1.000000; 1.000000;,
       41; 1.000000; 1.000000; 1.000000; 1.000000;,
       42; 1.000000; 1.000000; 1.000000; 1.000000;,
       43; 1.000000; 1.000000; 1.000000; 1.000000;,
       44; 1.000000; 1.000000; 1.000000; 1.000000;,
       45; 1.000000; 1.000000; 1.000000; 1.000000;,
       46; 1.000000; 1.000000; 1.000000; 1.000000;,
       47; 1.000000; 1.000000; 1.000000; 1.000000;,
       48; 1.000000; 1.000000; 1.000000; 1.000000;,
       49; 1.000000; 1.000000; 1.000000; 1.000000;,
       50; 1.000000; 1.000000; 1.000000; 1.000000;,
       51; 1.000000; 1.000000; 1.000000; 1.000000;,
       52; 1.000000; 1.000000; 1.000000; 1.000000;,
       53; 1.000000; 1.000000; 1.000000; 1.000000;,
       54; 1.000000; 1.000000; 1.000000; 1.000000;,
       55; 1.000000; 1.000000; 1.000000; 1.000000;,
       56; 1.000000; 1.000000; 1.000000; 1.000000;,
       57; 1.000000; 1.000000; 1.000000; 1.000000;,
       58; 1.000000; 1.000000; 1.000000; 1.000000;,
       59; 1.000000; 1.000000; 1.000000; 1.000000;,
       60; 1.000000; 1.000000; 1.000000; 1.000000;,
       61; 1.000000; 1.000000; 1.000000; 1.000000;,
       62; 1.000000; 1.000000; 1.000000; 1.000000;,
       63; 1.000000; 1.000000; 1.000000; 1.000000;,
       64; 1.000000; 1.000000; 1.000000; 1.000000;,
       65; 1.000000; 1.000000; 1.000000; 1.000000;,
       66; 1.000000; 1.000000; 1.000000; 1.000000;,
       67; 1.000000; 1.000000; 1.000000; 1.000000;,
       68; 1.000000; 1.000000; 1.000000; 1.000000;,
       69; 1.000000; 1.000000; 1.000000; 1.000000;,
       70; 1.000000; 1.000000; 1.000000; 1.000000;,
       71; 1.000000; 1.000000; 1.000000; 1.000000;,
       72; 1.000000; 1.000000; 1.000000; 1.000000;,
       73; 1.000000; 1.000000; 1.000000; 1.000000;,
       74; 1.000000; 1.000000; 1.000000; 1.000000;,
       75; 1.000000; 1.000000; 1.000000; 1.000000;,
       76; 1.000000; 1.000000; 1.000000; 1.000000;,
       77; 1.000000; 1.000000; 1.000000; 1.000000;,
       78; 1.000000; 1.000000; 1.000000; 1.000000;,
       79; 1.000000; 1.000000; 1.000000; 1.000000;,
       80; 1.000000; 1.000000; 1.000000; 1.000000;,
       81; 1.000000; 1.000000; 1.000000; 1.000000;,
       82; 1.000000; 1.000000; 1.000000; 1.000000;,
       83; 1.000000; 1.000000; 1.000000; 1.000000;,
       84; 1.000000; 1.000000; 1.000000; 1.000000;,
       85; 1.000000; 1.000000; 1.000000; 1.000000;,
       86; 1.000000; 1.000000; 1.000000; 1.000000;,
       87; 1.000000; 1.000000; 1.000000; 1.000000;,
       88; 1.000000; 1.000000; 1.000000; 1.000000;,
       89; 1.000000; 1.000000; 1.000000; 1.000000;,
       90; 1.000000; 1.000000; 1.000000; 1.000000;,
       91; 1.000000; 1.000000; 1.000000; 1.000000;,
       92; 1.000000; 1.000000; 1.000000; 1.000000;,
       93; 1.000000; 1.000000; 1.000000; 1.000000;,
       94; 1.000000; 1.000000; 1.000000; 1.000000;,
       95; 1.000000; 1.000000; 1.000000; 1.000000;,
       96; 1.000000; 1.000000; 1.000000; 1.000000;,
       97; 1.000000; 1.000000; 1.000000; 1.000000;,
       98; 1.000000; 1.000000; 1.000000; 1.000000;,
       99; 1.000000; 1.000000; 1.000000; 1.000000;,
       100; 1.000000; 1.000000; 1.000000; 1.000000;,
       101; 1.000000; 1.000000; 1.000000; 1.000000;,
       102; 1.000000; 1.000000; 1.000000; 1.000000;,
       103; 1.000000; 1.000000; 1.000000; 1.000000;,
       104; 1.000000; 1.000000; 1.000000; 1.000000;,
       105; 1.000000; 1.000000; 1.000000; 1.000000;,
       106; 1.000000; 1.000000; 1.000000; 1.000000;,
       107; 1.000000; 1.000000; 1.000000; 1.000000;,
       108; 1.000000; 1.000000; 1.000000; 1.000000;,
       109; 1.000000; 1.000000; 1.000000; 1.000000;,
       110; 1.000000; 1.000000; 1.000000; 1.000000;,
       111; 1.000000; 1.000000; 1.000000; 1.000000;,
       112; 1.000000; 1.000000; 1.000000; 1.000000;,
       113; 1.000000; 1.000000; 1.000000; 1.000000;,
       114; 1.000000; 1.000000; 1.000000; 1.000000;,
       115; 1.000000; 1.000000; 1.000000; 1.000000;,
       116; 1.000000; 1.000000; 1.000000; 1.000000;,
       117; 1.000000; 1.000000; 1.000000; 1.000000;,
       118; 1.000000; 1.000000; 1.000000; 1.000000;,
       119; 1.000000; 1.000000; 1.000000; 1.000000;,
       120; 1.000000; 1.000000; 1.000000; 1.000000;,
       121; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       84;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0;

       Material M_MedicalCabaret {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_MedicalCabaret_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "sm_cabaret";
       122;
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
       10,
       11,
       12,
       13,
       14,
       15,
       16,
       17,
       18,
       19,
       20,
       21,
       22,
       23,
       24,
       25,
       26,
       27,
       28,
       29,
       30,
       31,
       32,
       33,
       34,
       35,
       36,
       37,
       38,
       39,
       40,
       41,
       42,
       43,
       44,
       45,
       46,
       47,
       48,
       49,
       50,
       51,
       52,
       53,
       54,
       55,
       56,
       57,
       58,
       59,
       60,
       61,
       62,
       63,
       64,
       65,
       66,
       67,
       68,
       69,
       70,
       71,
       72,
       73,
       74,
       75,
       76,
       77,
       78,
       79,
       80,
       81,
       82,
       83,
       84,
       85,
       86,
       87,
       88,
       89,
       90,
       91,
       92,
       93,
       94,
       95,
       96,
       97,
       98,
       99,
       100,
       101,
       102,
       103,
       104,
       105,
       106,
       107,
       108,
       109,
       110,
       111,
       112,
       113,
       114,
       115,
       116,
       117,
       118,
       119,
       120,
       121;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000;
          1.000000, -0.000000, -0.000000, 0.000000,
          -0.000000, -0.000000, 1.000000, 0.000000,
          0.000000, -1.000000, -0.000000, 0.000000,
          -0.000000, 0.000000, -0.000000, 1.000000;;
      }


     }
   }
}

// Start of Animation

AnimationSet Take_001 {
   Animation {
      {sm_cabaret}

      AnimationKey {
       2;
       1;
       0; 3; 0.000000, 0.000000, 0.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }
      AnimationKey {
       1;
       1;
       0; 3; 1.000000, 1.000000, 1.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }
      AnimationKey {
       0;
       1;
       0; 4; 0.707107, 0.707107, -0.000000, -0.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }

   }

}
