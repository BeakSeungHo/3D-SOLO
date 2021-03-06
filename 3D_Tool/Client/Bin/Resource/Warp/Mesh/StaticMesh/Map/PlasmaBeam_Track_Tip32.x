xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Sat May 13 21:52:39 2017

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

   Frame PlasmaBeam_Track_Tip32 {
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
       55;
       0.000000; 2.571464; -1.166597;,
       0.000000; -2.571464; -1.166597;,
       -32.000000; 2.571464; -1.166597;,
       -32.000000; -2.571464; -1.166597;,
       -34.052025; 2.038126; -1.166597;,
       -34.807205; 0.000002; -1.166597;,
       -34.052025; -2.038124; -1.166597;,
       -38.488548; 4.267521; 0.000000;,
       -36.124290; 6.084488; -2.606499;,
       -37.927658; 3.543123; -2.606499;,
       -36.124290; 7.328470; 0.000000;,
       -32.000000; 6.822953; -2.606499;,
       -32.000000; 8.217912; -0.000001;,
       0.000000; 8.217912; -0.000001;,
       0.000000; 6.822953; -2.606499;,
       0.000000; -8.217912; -0.000000;,
       -32.000000; -8.217912; -0.000000;,
       0.000000; -6.822958; -2.606499;,
       -32.000000; -6.822958; -2.606499;,
       -36.124290; -7.328462; -0.000001;,
       -36.124290; -6.084477; -2.606499;,
       -38.488548; -4.267515; -0.000000;,
       -37.927658; -3.543118; -2.606499;,
       -39.767326; 0.000002; 0.000000;,
       -38.900208; 0.000002; -2.606499;,
       -32.000000; -3.281141; -2.606499;,
       0.000000; -2.571464; -1.166597;,
       0.000000; -3.281141; -2.606499;,
       -32.000000; -2.571464; -1.166597;,
       -34.052025; -2.038124; -1.166597;,
       -34.832905; -2.600614; -2.606499;,
       -34.807205; 0.000002; -1.166597;,
       -36.124290; 0.000002; -2.606499;,
       -34.832905; 2.600619; -2.606499;,
       -34.052025; 2.038126; -1.166597;,
       -32.000000; 3.281145; -2.606499;,
       -32.000000; 2.571464; -1.166597;,
       0.000000; 3.281145; -2.606499;,
       0.000000; 2.571464; -1.166597;,
       -32.000000; -3.281141; -2.606499;,
       -36.124290; -6.084477; -2.606499;,
       -34.832905; -2.600614; -2.606499;,
       -32.000000; -6.822958; -2.606499;,
       0.000000; -3.281141; -2.606499;,
       0.000000; -6.822958; -2.606499;,
       0.000000; 3.281145; -2.606499;,
       -32.000000; 3.281145; -2.606499;,
       0.000000; 6.822953; -2.606499;,
       -32.000000; 6.822953; -2.606499;,
       -36.124290; 6.084488; -2.606499;,
       -34.832905; 2.600619; -2.606499;,
       -37.927658; 3.543123; -2.606499;,
       -36.124290; 0.000002; -2.606499;,
       -38.900208; 0.000002; -2.606499;,
       -37.927658; -3.543118; -2.606499;;
       47;
       3;0, 1, 2;,
       3;2, 1, 3;,
       3;2, 3, 4;,
       3;4, 3, 5;,
       3;3, 6, 5;,
       3;7, 8, 9;,
       3;10, 8, 7;,
       3;10, 11, 8;,
       3;12, 11, 10;,
       3;12, 13, 11;,
       3;11, 13, 14;,
       3;15, 16, 17;,
       3;17, 16, 18;,
       3;16, 19, 18;,
       3;18, 19, 20;,
       3;19, 21, 20;,
       3;20, 21, 22;,
       3;23, 22, 21;,
       3;24, 22, 23;,
       3;24, 23, 9;,
       3;9, 23, 7;,
       3;25, 26, 27;,
       3;28, 26, 25;,
       3;28, 25, 29;,
       3;29, 25, 30;,
       3;29, 30, 31;,
       3;31, 30, 32;,
       3;33, 31, 32;,
       3;34, 31, 33;,
       3;35, 34, 33;,
       3;36, 34, 35;,
       3;37, 36, 35;,
       3;38, 36, 37;,
       3;39, 40, 41;,
       3;42, 40, 39;,
       3;43, 42, 39;,
       3;44, 42, 43;,
       3;45, 46, 47;,
       3;47, 46, 48;,
       3;48, 46, 49;,
       3;49, 46, 50;,
       3;51, 49, 50;,
       3;50, 52, 51;,
       3;51, 52, 53;,
       3;53, 52, 54;,
       3;54, 52, 41;,
       3;54, 41, 40;;

      MeshNormals {
       55;
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       -0.828282; 0.476403; -0.294939;,
       -0.597624; 0.715581; -0.361648;,
       -0.881025; 0.363085; -0.303255;,
       -0.389028; 0.824409; -0.411105;,
       -0.086930; 0.883668; -0.459972;,
       -0.093811; 0.877786; -0.469778;,
       0.000000; 0.881674; -0.471859;,
       0.000000; 0.881674; -0.471859;,
       0.000000; -0.881675; -0.471857;,
       -0.062510; -0.879951; -0.470935;,
       0.000000; -0.881675; -0.471857;,
       -0.115865; -0.882816; -0.455204;,
       -0.389030; -0.824408; -0.411105;,
       -0.597624; -0.715581; -0.361648;,
       -0.828281; -0.476404; -0.294939;,
       -0.881025; -0.363086; -0.303255;,
       -0.953649; -0.000000; -0.300921;,
       -0.948870; -0.000000; -0.315666;,
       0.109520; 0.889136; -0.444345;,
       0.000000; 0.896973; -0.442086;,
       0.000000; 0.896973; -0.442086;,
       0.114270; 0.891097; -0.439190;,
       0.442183; 0.734644; -0.514561;,
       0.606383; 0.539644; -0.584024;,
       0.783328; 0.000000; -0.621608;,
       0.737875; 0.000000; -0.674938;,
       0.606383; -0.539643; -0.584025;,
       0.442182; -0.734643; -0.514562;,
       0.145930; -0.884111; -0.443906;,
       0.076124; -0.894369; -0.440805;,
       0.000000; -0.896972; -0.442088;,
       0.000000; -0.896972; -0.442088;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;;
       47;
       3;0, 1, 2;,
       3;2, 1, 3;,
       3;2, 3, 4;,
       3;4, 3, 5;,
       3;3, 6, 5;,
       3;7, 8, 9;,
       3;10, 8, 7;,
       3;10, 11, 8;,
       3;12, 11, 10;,
       3;12, 13, 11;,
       3;11, 13, 14;,
       3;15, 16, 17;,
       3;17, 16, 18;,
       3;16, 19, 18;,
       3;18, 19, 20;,
       3;19, 21, 20;,
       3;20, 21, 22;,
       3;23, 22, 21;,
       3;24, 22, 23;,
       3;24, 23, 9;,
       3;9, 23, 7;,
       3;25, 26, 27;,
       3;28, 26, 25;,
       3;28, 25, 29;,
       3;29, 25, 30;,
       3;29, 30, 31;,
       3;31, 30, 32;,
       3;33, 31, 32;,
       3;34, 31, 33;,
       3;35, 34, 33;,
       3;36, 34, 35;,
       3;37, 36, 35;,
       3;38, 36, 37;,
       3;39, 40, 41;,
       3;42, 40, 39;,
       3;43, 42, 39;,
       3;44, 42, 43;,
       3;45, 46, 47;,
       3;47, 46, 48;,
       3;48, 46, 49;,
       3;49, 46, 50;,
       3;51, 49, 50;,
       3;50, 52, 51;,
       3;51, 52, 53;,
       3;53, 52, 54;,
       3;54, 52, 41;,
       3;54, 41, 40;;
      }

      MeshTextureCoords {
       55;
       0.691895; 0.339600;,
       0.691895; 0.648926;,
       0.351074; 0.339600;,
       0.351074; 0.648926;,
       0.342041; 0.395264;,
       0.338623; 0.505371;,
       0.342041; 0.618164;,
       0.469482; 0.000031;,
       0.476563; 0.087402;,
       0.471436; 0.087402;,
       0.476807; 0.000031;,
       0.488525; 0.087402;,
       0.488281; 0.000031;,
       0.716797; 0.000031;,
       0.716797; 0.087402;,
       0.193604; 0.000031;,
       0.419678; 0.000031;,
       0.193604; 0.087402;,
       0.419434; 0.087402;,
       0.433838; 0.000031;,
       0.434082; 0.087402;,
       0.440918; 0.000031;,
       0.439209; 0.087402;,
       0.452393; 0.000031;,
       0.452393; 0.087402;,
       0.419434; 0.282227;,
       0.193604; 0.339600;,
       0.193604; 0.282227;,
       0.419434; 0.339600;,
       0.427979; 0.339600;,
       0.431641; 0.282227;,
       0.452393; 0.339600;,
       0.452393; 0.282227;,
       0.478760; 0.282227;,
       0.482666; 0.339600;,
       0.488770; 0.282227;,
       0.488770; 0.339600;,
       0.716797; 0.282227;,
       0.716797; 0.339600;,
       0.419434; 0.282227;,
       0.434082; 0.087402;,
       0.431641; 0.282227;,
       0.419434; 0.087402;,
       0.193604; 0.282227;,
       0.193604; 0.087402;,
       0.716797; 0.282227;,
       0.488770; 0.282227;,
       0.716797; 0.087402;,
       0.488525; 0.087402;,
       0.476563; 0.087402;,
       0.478760; 0.282227;,
       0.471436; 0.087402;,
       0.452393; 0.282227;,
       0.452393; 0.087402;,
       0.439209; 0.087402;;
      }

      FVFData {
       258;
       110;
       939524096,
       1051795456,
       939524096,
       1059487744,
       1062535168,
       1051795456,
       1062535168,
       1059487744,
       1063297024,
       1052852224,
       1063583744,
       1056907264,
       1063297024,
       1058963456,
       1064951808,
       1048264704,
       1064075264,
       1041039360,
       1064747008,
       1049862144,
       1064075264,
       1032003584,
       1062535168,
       1036025856,
       1062535168,
       939524096,
       939524096,
       939524096,
       939524096,
       1036025856,
       939524096,
       1065353216,
       1062535168,
       1065353216,
       939524096,
       1063714816,
       1062535168,
       1063714816,
       1064075264,
       1064222720,
       1064075264,
       1062985728,
       1064951808,
       1061175296,
       1064747008,
       1060454400,
       1065353216,
       1056907264,
       1065107456,
       1056907264,
       1062535168,
       1060200448,
       939524096,
       1059487744,
       939524096,
       1060200448,
       1062535168,
       1059487744,
       1063297024,
       1058963456,
       1063591936,
       1059520512,
       1063583744,
       1056907264,
       1064075264,
       1056907264,
       1063591936,
       1051738112,
       1063297024,
       1052852224,
       1062535168,
       1050378240,
       1062535168,
       1051795456,
       939524096,
       1050378240,
       939524096,
       1051795456,
       1062535168,
       1060200448,
       1064075264,
       1062985728,
       1063591936,
       1059520512,
       1062535168,
       1063714816,
       939524096,
       1060200448,
       939524096,
       1063714816,
       939524096,
       1050378240,
       1062535168,
       1050378240,
       939524096,
       1036025856,
       1062535168,
       1036025856,
       1064075264,
       1041039360,
       1063591936,
       1051738112,
       1064747008,
       1049862144,
       1064075264,
       1056907264,
       1065107456,
       1056907264,
       1064747008,
       1060454400;
      }

      MeshVertexColors {
       55;
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
       54; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       47;
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

       Material M_PlasmaBeam_Track {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_PlasmaBeam_Track_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "PlasmaBeam_Track_Tip32";
       55;
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
       54;
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
      {PlasmaBeam_Track_Tip32}

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
