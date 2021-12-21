xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.24
// Website: http://www.unwrap3d.com
// Time: Fri Jun 16 17:04:48 2017

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

   Frame laser_fixed {
      FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, -0.000000, 1.000000, 0.000000,
       -0.000000, -1.000000, -0.000000, 0.000000,
       0.000000, 0.000000, -0.000000, 1.000000;;
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
       120;
       5.892880; 0.000000; 3.402252;,
       3.402260; 0.000000; 5.892878;,
       3.402260; 2.380102; 5.892878;,
       5.892880; 2.380101; 3.402252;,
       6.804509; -0.000000; -0.000003;,
       6.804509; 2.380101; -0.000003;,
       -6.804511; 0.000000; 0.000003;,
       -5.892880; -0.000000; -3.402252;,
       -5.892880; 2.380102; -3.402252;,
       -6.804511; 2.380102; 0.000003;,
       -5.892880; 0.000000; 3.402258;,
       -5.892880; 2.380103; 3.402258;,
       -3.402254; 0.000000; 5.892880;,
       -3.402254; 2.380101; 5.892882;,
       0.000001; 0.000000; 6.804512;,
       0.000001; 2.380102; 6.804512;,
       5.892876; -0.000000; -3.402257;,
       6.804509; -0.000000; -0.000003;,
       6.804509; 2.380101; -0.000003;,
       5.892876; 2.380101; -3.402256;,
       3.402252; -0.000000; -5.892879;,
       3.402252; 2.380102; -5.892878;,
       -0.000003; -0.000000; -6.804508;,
       -0.000003; 2.380102; -6.804508;,
       -3.402257; -0.000000; -5.892877;,
       -3.402257; 2.380101; -5.892877;,
       -4.892359; 4.903086; 4.892363;,
       -4.903674; 6.444019; 4.903678;,
       0.000001; 6.444018; 7.047398;,
       0.000001; 4.903086; 7.031136;,
       4.892365; 4.903086; 4.892358;,
       4.903680; 6.444019; 4.903673;,
       7.047396; 6.444019; -0.000002;,
       7.031135; 4.903086; -0.000002;,
       4.892359; 4.903086; -4.892362;,
       7.031135; 4.903086; -0.000002;,
       7.047396; 6.444019; -0.000002;,
       4.903673; 6.444019; -4.903677;,
       -0.000003; 6.444018; -7.047395;,
       -0.000003; 4.903086; -7.031134;,
       -4.892361; 4.903086; -4.892359;,
       -4.903677; 6.444019; -4.903674;,
       -7.047396; 6.444019; 0.000003;,
       -7.031135; 4.903086; 0.000003;,
       3.131366; 11.066818; 3.131362;,
       4.500289; 11.066818; -0.000001;,
       7.047396; 6.444019; -0.000002;,
       4.903680; 6.444019; 4.903673;,
       0.000001; 6.444018; 7.047398;,
       0.000001; 11.066816; 4.500290;,
       -4.903674; 6.444019; 4.903678;,
       -3.131363; 11.066818; 3.131365;,
       -4.500289; 11.066818; 0.000003;,
       -7.047396; 6.444019; 0.000003;,
       -4.903677; 6.444019; -4.903674;,
       -3.131364; 11.066818; -3.131361;,
       -0.000002; 11.066816; -4.500288;,
       -0.000003; 6.444018; -7.047395;,
       4.903673; 6.444019; -4.903677;,
       3.131361; 11.066818; -3.131363;,
       4.500289; 11.066818; -0.000001;,
       7.047396; 6.444019; -0.000002;,
       0.000001; 4.903086; 7.031136;,
       4.892365; 4.903086; 4.892358;,
       -0.000000; 4.903086; 0.000001;,
       7.031135; 4.903086; -0.000002;,
       4.892359; 4.903086; -4.892362;,
       -0.000003; 4.903086; -7.031134;,
       -4.892361; 4.903086; -4.892359;,
       -7.031135; 4.903086; 0.000003;,
       -4.892359; 4.903086; 4.892363;,
       -5.892880; 2.380103; 3.402258;,
       -6.804511; 2.380102; 0.000003;,
       -0.000001; 2.380097; 0.000001;,
       -5.892880; 2.380102; -3.402252;,
       -3.402257; 2.380101; -5.892877;,
       -0.000003; 2.380102; -6.804508;,
       3.402252; 2.380102; -5.892878;,
       5.892876; 2.380101; -3.402256;,
       6.804509; 2.380101; -0.000003;,
       5.892880; 2.380101; 3.402252;,
       3.402260; 2.380102; 5.892878;,
       0.000001; 2.380102; 6.804512;,
       -3.402254; 2.380101; 5.892882;,
       -3.131363; 11.066818; 3.131365;,
       -4.500289; 11.066818; 0.000003;,
       -0.000001; 11.066835; 0.000002;,
       -3.131364; 11.066818; -3.131361;,
       -0.000002; 11.066816; -4.500288;,
       3.131361; 11.066818; -3.131363;,
       4.500289; 11.066818; -0.000001;,
       3.131366; 11.066818; 3.131362;,
       0.000001; 11.066816; 4.500290;,
       -1.701644; 11.066897; 1.701645;,
       -2.445545; 11.066899; 0.000001;,
       0.000000; 12.265228; 0.000001;,
       -1.701644; 11.066897; -1.701643;,
       -0.000000; 11.066897; -2.445545;,
       1.701644; 11.066897; -1.701645;,
       2.445546; 11.066899; -0.000001;,
       1.701646; 11.066897; 1.701644;,
       0.000001; 11.066897; 2.445546;,
       -2.647191; 2.380123; 2.647190;,
       -2.647191; 5.036372; 2.647191;,
       -0.000002; 5.036372; 3.804452;,
       -0.000001; 2.380124; 3.804451;,
       2.647189; 5.036372; 2.647188;,
       2.647189; 2.380123; 2.647188;,
       3.804448; 5.036373; -0.000001;,
       3.804448; 2.380124; -0.000001;,
       3.804448; 2.380124; -0.000001;,
       3.804448; 5.036373; -0.000001;,
       2.647185; 5.036372; -2.647188;,
       2.647185; 2.380123; -2.647189;,
       -0.000004; 5.036372; -3.804448;,
       -0.000004; 2.380123; -3.804449;,
       -2.647192; 5.036372; -2.647186;,
       -2.647192; 2.380123; -2.647187;,
       -3.804452; 5.036373; 0.000002;,
       -3.804452; 2.380123; 0.000002;;
       108;
       3;2, 1, 0;,
       3;0, 3, 2;,
       3;3, 0, 4;,
       3;4, 5, 3;,
       3;8, 7, 6;,
       3;6, 9, 8;,
       3;9, 6, 10;,
       3;10, 11, 9;,
       3;11, 10, 12;,
       3;12, 13, 11;,
       3;13, 12, 14;,
       3;14, 15, 13;,
       3;15, 14, 1;,
       3;1, 2, 15;,
       3;18, 17, 16;,
       3;16, 19, 18;,
       3;19, 16, 20;,
       3;20, 21, 19;,
       3;21, 20, 22;,
       3;22, 23, 21;,
       3;23, 22, 24;,
       3;24, 25, 23;,
       3;25, 24, 7;,
       3;7, 8, 25;,
       3;28, 27, 26;,
       3;26, 29, 28;,
       3;28, 29, 30;,
       3;30, 31, 28;,
       3;32, 31, 30;,
       3;30, 33, 32;,
       3;36, 35, 34;,
       3;34, 37, 36;,
       3;38, 37, 34;,
       3;34, 39, 38;,
       3;38, 39, 40;,
       3;40, 41, 38;,
       3;42, 41, 40;,
       3;40, 43, 42;,
       3;42, 43, 26;,
       3;26, 27, 42;,
       3;46, 45, 44;,
       3;44, 47, 46;,
       3;48, 47, 44;,
       3;44, 49, 48;,
       3;50, 48, 49;,
       3;49, 51, 50;,
       3;50, 51, 52;,
       3;52, 53, 50;,
       3;54, 53, 52;,
       3;52, 55, 54;,
       3;54, 55, 56;,
       3;56, 57, 54;,
       3;58, 57, 56;,
       3;56, 59, 58;,
       3;58, 59, 60;,
       3;60, 61, 58;,
       3;64, 63, 62;,
       3;65, 63, 64;,
       3;64, 66, 65;,
       3;67, 66, 64;,
       3;64, 68, 67;,
       3;69, 68, 64;,
       3;64, 70, 69;,
       3;62, 70, 64;,
       3;73, 72, 71;,
       3;73, 74, 72;,
       3;73, 75, 74;,
       3;73, 76, 75;,
       3;73, 77, 76;,
       3;73, 78, 77;,
       3;73, 79, 78;,
       3;73, 80, 79;,
       3;73, 81, 80;,
       3;73, 82, 81;,
       3;82, 73, 83;,
       3;73, 71, 83;,
       3;86, 85, 84;,
       3;86, 87, 85;,
       3;86, 88, 87;,
       3;86, 89, 88;,
       3;89, 86, 90;,
       3;86, 91, 90;,
       3;86, 92, 91;,
       3;86, 84, 92;,
       3;95, 94, 93;,
       3;95, 96, 94;,
       3;95, 97, 96;,
       3;95, 98, 97;,
       3;95, 99, 98;,
       3;95, 100, 99;,
       3;95, 101, 100;,
       3;95, 93, 101;,
       3;104, 103, 102;,
       3;102, 105, 104;,
       3;106, 104, 105;,
       3;105, 107, 106;,
       3;108, 106, 107;,
       3;107, 109, 108;,
       3;112, 111, 110;,
       3;110, 113, 112;,
       3;114, 112, 113;,
       3;113, 115, 114;,
       3;116, 114, 115;,
       3;115, 117, 116;,
       3;118, 116, 117;,
       3;117, 119, 118;,
       3;103, 118, 119;,
       3;119, 102, 103;;

      MeshNormals {
       120;
       0.818111; 0.000000; 0.575060;,
       0.420974; 0.000000; 0.907072;,
       0.575062; 0.000000; 0.818110;,
       0.907073; 0.000000; 0.420973;,
       0.965926; 0.000000; 0.258818;,
       0.965926; 0.000000; 0.258818;,
       -0.996035; 0.000000; -0.088962;,
       -0.818111; 0.000000; -0.575061;,
       -0.907073; -0.000000; -0.420974;,
       -0.996035; 0.000000; 0.088962;,
       -0.907073; 0.000000; 0.420974;,
       -0.818110; -0.000000; 0.575061;,
       -0.575061; -0.000000; 0.818111;,
       -0.420974; -0.000000; 0.907073;,
       -0.088962; -0.000000; 0.996035;,
       0.088963; 0.000000; 0.996035;,
       0.907073; 0.000000; -0.420974;,
       0.965926; 0.000000; -0.258820;,
       0.965926; 0.000000; -0.258820;,
       0.818110; 0.000000; -0.575061;,
       0.575061; 0.000000; -0.818111;,
       0.420973; 0.000000; -0.907073;,
       0.088962; 0.000000; -0.996035;,
       -0.088962; 0.000000; -0.996035;,
       -0.420974; 0.000000; -0.907073;,
       -0.575061; 0.000000; -0.818110;,
       -0.707069; -0.010384; 0.707069;,
       -0.707069; -0.010384; 0.707069;,
       0.000000; -0.010553; 0.999944;,
       0.000000; -0.010552; 0.999944;,
       0.707069; -0.010384; 0.707068;,
       0.707069; -0.010384; 0.707068;,
       0.916227; -0.009669; 0.400543;,
       0.916227; -0.009669; 0.400543;,
       0.707068; -0.010384; -0.707069;,
       0.916227; -0.009669; -0.400544;,
       0.916227; -0.009669; -0.400544;,
       0.707068; -0.010384; -0.707069;,
       -0.000000; -0.010552; -0.999944;,
       -0.000000; -0.010552; -0.999944;,
       -0.707069; -0.010384; -0.707068;,
       -0.707069; -0.010384; -0.707068;,
       -0.999944; -0.010553; 0.000000;,
       -0.999944; -0.010553; 0.000000;,
       0.621618; 0.476638; 0.621617;,
       0.817943; 0.450676; 0.357576;,
       0.817943; 0.450676; 0.357576;,
       0.621618; 0.476638; 0.621617;,
       0.126604; 0.478700; 0.868803;,
       -0.126603; 0.478700; 0.868803;,
       -0.621617; 0.476638; 0.621618;,
       -0.621617; 0.476638; 0.621618;,
       -0.875850; 0.482583; 0.000000;,
       -0.875850; 0.482583; 0.000000;,
       -0.621618; 0.476638; -0.621617;,
       -0.621618; 0.476638; -0.621617;,
       -0.000000; 0.482583; -0.875850;,
       -0.000000; 0.482583; -0.875850;,
       0.621617; 0.476638; -0.621618;,
       0.621617; 0.476638; -0.621618;,
       0.817942; 0.450676; -0.357577;,
       0.817942; 0.450676; -0.357577;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000001; 1.000000; -0.000000;,
       0.000001; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000001; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000001;,
       -0.000000; 1.000000; 0.000001;,
       -0.000000; 1.000000; 0.000001;,
       -0.000000; 1.000000; 0.000000;,
       -0.000001; 1.000000; -0.000000;,
       -0.000000; 1.000000; -0.000001;,
       -0.000000; 1.000000; -0.000001;,
       -0.000000; 1.000000; -0.000001;,
       0.000000; 1.000000; -0.000000;,
       -0.000003; 1.000000; 0.000003;,
       -0.000004; 1.000000; 0.000000;,
       -0.000000; 1.000000; -0.000000;,
       -0.000003; 1.000000; -0.000003;,
       -0.000000; 1.000000; -0.000004;,
       0.000003; 1.000000; -0.000003;,
       0.000004; 1.000000; -0.000000;,
       0.000003; 1.000000; 0.000003;,
       0.000000; 1.000000; 0.000004;,
       -0.315193; 0.895157; 0.315194;,
       -0.440019; 0.897989; 0.000000;,
       -0.000000; 1.000000; -0.000000;,
       -0.315193; 0.895157; -0.315194;,
       -0.000000; 0.897988; -0.440019;,
       0.315193; 0.895157; -0.315194;,
       0.440019; 0.897989; -0.000000;,
       0.315193; 0.895157; 0.315194;,
       0.000000; 0.897988; 0.440019;,
       -0.609627; -0.000000; 0.792689;,
       -0.792688; -0.000000; 0.609627;,
       -0.144199; -0.000000; 0.989549;,
       0.144199; -0.000000; 0.989549;,
       0.609627; -0.000000; 0.792688;,
       0.792689; -0.000000; 0.609626;,
       0.916270; -0.000000; 0.400561;,
       0.916270; -0.000000; 0.400561;,
       0.916269; 0.000000; -0.400563;,
       0.916269; 0.000000; -0.400563;,
       0.792688; 0.000000; -0.609627;,
       0.609626; 0.000000; -0.792689;,
       0.144199; 0.000000; -0.989549;,
       -0.144199; 0.000000; -0.989549;,
       -0.609627; 0.000000; -0.792688;,
       -0.792689; 0.000000; -0.609627;,
       -0.989549; 0.000000; -0.144199;,
       -0.989549; -0.000000; 0.144199;;
       108;
       3;2, 1, 0;,
       3;0, 3, 2;,
       3;3, 0, 4;,
       3;4, 5, 3;,
       3;8, 7, 6;,
       3;6, 9, 8;,
       3;9, 6, 10;,
       3;10, 11, 9;,
       3;11, 10, 12;,
       3;12, 13, 11;,
       3;13, 12, 14;,
       3;14, 15, 13;,
       3;15, 14, 1;,
       3;1, 2, 15;,
       3;18, 17, 16;,
       3;16, 19, 18;,
       3;19, 16, 20;,
       3;20, 21, 19;,
       3;21, 20, 22;,
       3;22, 23, 21;,
       3;23, 22, 24;,
       3;24, 25, 23;,
       3;25, 24, 7;,
       3;7, 8, 25;,
       3;28, 27, 26;,
       3;26, 29, 28;,
       3;28, 29, 30;,
       3;30, 31, 28;,
       3;32, 31, 30;,
       3;30, 33, 32;,
       3;36, 35, 34;,
       3;34, 37, 36;,
       3;38, 37, 34;,
       3;34, 39, 38;,
       3;38, 39, 40;,
       3;40, 41, 38;,
       3;42, 41, 40;,
       3;40, 43, 42;,
       3;42, 43, 26;,
       3;26, 27, 42;,
       3;46, 45, 44;,
       3;44, 47, 46;,
       3;48, 47, 44;,
       3;44, 49, 48;,
       3;50, 48, 49;,
       3;49, 51, 50;,
       3;50, 51, 52;,
       3;52, 53, 50;,
       3;54, 53, 52;,
       3;52, 55, 54;,
       3;54, 55, 56;,
       3;56, 57, 54;,
       3;58, 57, 56;,
       3;56, 59, 58;,
       3;58, 59, 60;,
       3;60, 61, 58;,
       3;64, 63, 62;,
       3;65, 63, 64;,
       3;64, 66, 65;,
       3;67, 66, 64;,
       3;64, 68, 67;,
       3;69, 68, 64;,
       3;64, 70, 69;,
       3;62, 70, 64;,
       3;73, 72, 71;,
       3;73, 74, 72;,
       3;73, 75, 74;,
       3;73, 76, 75;,
       3;73, 77, 76;,
       3;73, 78, 77;,
       3;73, 79, 78;,
       3;73, 80, 79;,
       3;73, 81, 80;,
       3;73, 82, 81;,
       3;82, 73, 83;,
       3;73, 71, 83;,
       3;86, 85, 84;,
       3;86, 87, 85;,
       3;86, 88, 87;,
       3;86, 89, 88;,
       3;89, 86, 90;,
       3;86, 91, 90;,
       3;86, 92, 91;,
       3;86, 84, 92;,
       3;95, 94, 93;,
       3;95, 96, 94;,
       3;95, 97, 96;,
       3;95, 98, 97;,
       3;95, 99, 98;,
       3;95, 100, 99;,
       3;95, 101, 100;,
       3;95, 93, 101;,
       3;104, 103, 102;,
       3;102, 105, 104;,
       3;106, 104, 105;,
       3;105, 107, 106;,
       3;108, 106, 107;,
       3;107, 109, 108;,
       3;112, 111, 110;,
       3;110, 113, 112;,
       3;114, 112, 113;,
       3;113, 115, 114;,
       3;116, 114, 115;,
       3;115, 117, 116;,
       3;118, 116, 117;,
       3;117, 119, 118;,
       3;103, 118, 119;,
       3;119, 102, 103;;
      }

      MeshTextureCoords {
       120;
       0.907715; 0.022385;,
       0.826660; 0.022354;,
       0.826660; 0.054626;,
       0.907715; 0.054657;,
       0.988770; 0.022415;,
       0.988770; 0.054688;,
       0.501953; 0.022369;,
       0.421143; 0.022430;,
       0.421143; 0.054688;,
       0.501953; 0.054657;,
       0.583008; 0.022339;,
       0.583008; 0.054596;,
       0.664063; 0.022339;,
       0.664063; 0.054596;,
       0.745605; 0.022339;,
       0.745605; 0.054626;,
       0.096802; 0.022888;,
       0.015717; 0.023041;,
       0.015778; 0.055298;,
       0.096863; 0.055176;,
       0.177856; 0.022751;,
       0.177856; 0.055023;,
       0.258789; 0.022629;,
       0.259033; 0.054901;,
       0.340088; 0.022522;,
       0.340088; 0.054779;,
       0.496582; 0.091553;,
       0.497314; 0.134766;,
       0.596191; 0.134766;,
       0.596191; 0.091553;,
       0.691895; 0.091553;,
       0.692383; 0.134766;,
       0.788086; 0.134766;,
       0.788086; 0.091553;,
       0.116394; 0.091553;,
       0.020477; 0.091553;,
       0.020477; 0.134766;,
       0.116394; 0.134766;,
       0.212280; 0.134766;,
       0.212402; 0.091553;,
       0.308350; 0.091553;,
       0.308105; 0.134766;,
       0.404053; 0.134766;,
       0.404297; 0.091553;,
       0.692871; 0.264404;,
       0.788574; 0.264404;,
       0.788086; 0.134766;,
       0.692383; 0.134766;,
       0.596191; 0.134766;,
       0.595703; 0.264404;,
       0.497314; 0.134766;,
       0.499756; 0.264404;,
       0.404053; 0.264404;,
       0.404053; 0.134766;,
       0.308105; 0.134766;,
       0.308105; 0.264404;,
       0.212158; 0.264404;,
       0.212280; 0.134766;,
       0.116394; 0.134766;,
       0.116333; 0.264404;,
       0.020477; 0.264404;,
       0.020477; 0.134766;,
       0.968750; 0.180664;,
       0.944336; 0.124329;,
       0.888184; 0.180664;,
       0.888184; 0.099670;,
       0.831543; 0.124329;,
       0.807129; 0.180664;,
       0.831543; 0.237061;,
       0.888184; 0.261719;,
       0.944336; 0.237061;,
       0.429932; 0.470215;,
       0.297852; 0.434814;,
       0.297852; 0.698730;,
       0.166016; 0.470215;,
       0.069336; 0.566895;,
       0.033966; 0.698730;,
       0.069336; 0.830566;,
       0.166016; 0.927246;,
       0.297852; 0.962891;,
       0.429932; 0.927246;,
       0.526367; 0.830566;,
       0.562012; 0.698730;,
       0.526367; 0.566895;,
       0.909668; 0.444824;,
       0.808105; 0.400391;,
       0.808105; 0.546387;,
       0.706055; 0.444824;,
       0.661621; 0.546387;,
       0.706055; 0.648438;,
       0.808105; 0.692871;,
       0.909668; 0.648438;,
       0.954102; 0.546387;,
       0.837891; 0.160156;,
       0.500000; 0.013557;,
       0.500000; 0.500000;,
       0.162354; 0.160156;,
       0.014137; 0.496338;,
       0.158936; 0.834961;,
       0.500000; 0.986816;,
       0.841309; 0.834961;,
       0.986328; 0.496338;,
       0.538086; 0.296631;,
       0.538086; 0.357666;,
       0.642578; 0.357666;,
       0.642578; 0.296631;,
       0.746582; 0.357666;,
       0.746582; 0.296631;,
       0.850586; 0.357666;,
       0.850586; 0.296631;,
       0.017441; 0.296631;,
       0.017441; 0.357666;,
       0.121643; 0.357666;,
       0.121643; 0.296631;,
       0.225830; 0.357666;,
       0.225830; 0.296631;,
       0.329834; 0.357666;,
       0.329834; 0.296631;,
       0.434082; 0.357666;,
       0.434082; 0.296631;;
      }

      MeshVertexColors {
       120;
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
       119; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       2;
       108;
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
       0,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
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

       Material M_Death_beam_base_INST {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "Stainless_D.jpg";
        }
       }

       Material M_REDDeathBeamLens_INST {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "Red.jpg";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "laser_fixed";
       120;
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
       119;
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
          1.000000, -0.000000, 0.000000, 0.000000,
          -0.000000, -0.000000, -1.000000, 0.000000,
          -0.000000, 1.000000, -0.000000, 0.000000,
          -0.000000, 0.000000, 0.000000, 1.000000;;
      }


     }
   }

// Start of Animation

AnimationSet Take_001 {
   Animation {
      {laser_fixed}

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
       0; 4; 0.707107, -0.707107, 0.000000, -0.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }

   }

}