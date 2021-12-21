xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.24
// Website: http://www.unwrap3d.com
// Time: Thu Jun 15 20:24:26 2017

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

   Frame sm_fence128_Light {
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
       108;
       5.493435; 14.031427; 2.065627;,
       5.493435; 17.568182; 2.065627;,
       122.506561; 14.031427; 2.065627;,
       122.506561; 17.568182; 2.065627;,
       5.493435; 17.568182; -2.065627;,
       122.506561; 17.568182; -2.065627;,
       5.493435; 17.568182; 2.065627;,
       122.506561; 17.568182; 2.065627;,
       126.508728; 192.000000; -2.746717;,
       126.508728; -0.000000; -2.746717;,
       128.000000; 192.000000; -1.255444;,
       128.000000; -0.000000; -1.255444;,
       128.000000; 192.000000; 1.255444;,
       128.000000; 0.000000; 1.255444;,
       126.508728; 192.000000; 2.746717;,
       126.508728; 0.000000; 2.746717;,
       122.506561; -0.000000; -2.746717;,
       126.508728; -0.000000; -2.746717;,
       122.506561; 192.000000; -2.746717;,
       126.508728; 192.000000; -2.746717;,
       128.000000; 192.000000; 1.255444;,
       128.000000; 192.000000; -1.255444;,
       128.000000; 0.000000; 1.255444;,
       128.000000; -0.000000; -1.255444;,
       122.506561; 0.000000; 2.746717;,
       122.506561; -0.000000; -2.746717;,
       122.506561; 192.000000; 2.746717;,
       122.506561; 192.000000; -2.746717;,
       122.506561; 0.000000; 2.746717;,
       122.506561; 192.000000; 2.746717;,
       126.508728; 0.000000; 2.746717;,
       126.508728; 192.000000; 2.746717;,
       1.380273; -0.000000; -2.746717;,
       1.380273; 192.000000; -2.746717;,
       0.000000; -0.000000; -1.366445;,
       0.000000; 192.000000; -1.366445;,
       0.000000; 0.000000; 1.366445;,
       0.000000; 192.000000; 1.366445;,
       1.380273; 0.000000; 2.746717;,
       1.380273; 192.000000; 2.746717;,
       1.380273; -0.000000; -2.746717;,
       5.493435; -0.000000; -2.746717;,
       1.380273; 192.000000; -2.746717;,
       5.493435; 192.000000; -2.746717;,
       5.493435; 0.000000; 2.746717;,
       5.493435; 192.000000; 2.746717;,
       5.493435; -0.000000; -2.746717;,
       5.493435; 192.000000; -2.746717;,
       0.000000; 0.000000; 1.366445;,
       0.000000; -0.000000; -1.366445;,
       0.000000; 192.000000; 1.366445;,
       0.000000; 192.000000; -1.366445;,
       1.380273; 192.000000; 2.746717;,
       5.493435; 192.000000; 2.746717;,
       1.380273; 0.000000; 2.746717;,
       5.493435; 0.000000; 2.746717;,
       5.493435; 184.937576; -2.065627;,
       122.506561; 184.937576; -2.065627;,
       5.493435; 190.079376; -2.065627;,
       122.506561; 190.079376; -2.065627;,
       5.493435; 184.937576; -2.065627;,
       5.493435; 184.937576; 2.065627;,
       122.506561; 184.937576; -2.065627;,
       122.506561; 184.937576; 2.065627;,
       5.493435; 184.937576; 2.065627;,
       5.493435; 190.079376; 2.065627;,
       122.506561; 184.937576; 2.065627;,
       122.506561; 190.079376; 2.065627;,
       5.493435; 190.079376; -2.065627;,
       122.506561; 190.079376; -2.065627;,
       5.493435; 190.079376; 2.065627;,
       122.506561; 190.079376; 2.065627;,
       5.493435; 14.031427; -2.065627;,
       122.506561; 14.031427; -2.065627;,
       5.493435; 17.568182; -2.065627;,
       122.506561; 17.568182; -2.065627;,
       5.493435; 14.031427; -2.065627;,
       5.493435; 14.031427; 2.065627;,
       122.506561; 14.031427; -2.065627;,
       122.506561; 14.031427; 2.065627;,
       5.493435; 0.000000; 2.746717;,
       5.493435; -0.000000; -2.746717;,
       1.380273; 0.000000; 2.746717;,
       1.380273; -0.000000; -2.746717;,
       0.000000; 0.000000; 1.366445;,
       0.000000; -0.000000; -1.366445;,
       122.506561; 0.000000; 2.746717;,
       126.508728; 0.000000; 2.746717;,
       122.506561; -0.000000; -2.746717;,
       126.508728; -0.000000; -2.746717;,
       128.000000; 0.000000; 1.255444;,
       128.000000; -0.000000; -1.255444;,
       122.506561; 16.200195; -0.000000;,
       5.493435; 16.200195; -0.000000;,
       122.506561; 187.833344; -0.000000;,
       5.493435; 187.833344; -0.000000;,
       5.493435; 192.000000; -2.746717;,
       5.493435; 192.000000; 2.746717;,
       1.380273; 192.000000; -2.746717;,
       1.380273; 192.000000; 2.746717;,
       0.000000; 192.000000; 1.366445;,
       0.000000; 192.000000; -1.366445;,
       122.506561; 192.000000; 2.746717;,
       122.506561; 192.000000; -2.746717;,
       126.508728; 192.000000; 2.746717;,
       126.508728; 192.000000; -2.746717;,
       128.000000; 192.000000; -1.255444;,
       128.000000; 192.000000; 1.255444;;
       58;
       3;2, 1, 0;,
       3;3, 1, 2;,
       3;6, 5, 4;,
       3;7, 5, 6;,
       3;10, 9, 8;,
       3;11, 9, 10;,
       3;14, 13, 12;,
       3;15, 13, 14;,
       3;18, 17, 16;,
       3;19, 17, 18;,
       3;22, 21, 20;,
       3;23, 21, 22;,
       3;26, 25, 24;,
       3;27, 25, 26;,
       3;30, 29, 28;,
       3;31, 29, 30;,
       3;34, 33, 32;,
       3;35, 33, 34;,
       3;38, 37, 36;,
       3;39, 37, 38;,
       3;42, 41, 40;,
       3;43, 41, 42;,
       3;46, 45, 44;,
       3;47, 45, 46;,
       3;50, 49, 48;,
       3;51, 49, 50;,
       3;54, 53, 52;,
       3;55, 53, 54;,
       3;58, 57, 56;,
       3;59, 57, 58;,
       3;62, 61, 60;,
       3;63, 61, 62;,
       3;66, 65, 64;,
       3;67, 65, 66;,
       3;70, 69, 68;,
       3;71, 69, 70;,
       3;74, 73, 72;,
       3;75, 73, 74;,
       3;78, 77, 76;,
       3;79, 77, 78;,
       3;82, 81, 80;,
       3;82, 83, 81;,
       3;84, 83, 82;,
       3;85, 83, 84;,
       3;88, 87, 86;,
       3;89, 87, 88;,
       3;89, 90, 87;,
       3;89, 91, 90;,
       3;94, 93, 92;,
       3;95, 93, 94;,
       3;98, 97, 96;,
       3;98, 99, 97;,
       3;98, 100, 99;,
       3;98, 101, 100;,
       3;104, 103, 102;,
       3;104, 105, 103;,
       3;104, 106, 105;,
       3;104, 107, 106;;

      MeshNormals {
       108;
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.707107; 0.000000; -0.707107;,
       0.707107; 0.000000; -0.707107;,
       0.707107; 0.000000; -0.707107;,
       0.707107; 0.000000; -0.707107;,
       0.707107; 0.000000; 0.707107;,
       0.707107; 0.000000; 0.707107;,
       0.707107; 0.000000; 0.707107;,
       0.707107; 0.000000; 0.707107;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       -0.707107; 0.000000; -0.707107;,
       -0.707107; 0.000000; -0.707107;,
       -0.707107; 0.000000; -0.707107;,
       -0.707107; 0.000000; -0.707107;,
       -0.707107; 0.000000; 0.707107;,
       -0.707107; 0.000000; 0.707107;,
       -0.707107; 0.000000; 0.707107;,
       -0.707107; 0.000000; 0.707107;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; -0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;,
       0.000000; 1.000000; -0.000000;;
       58;
       3;2, 1, 0;,
       3;3, 1, 2;,
       3;6, 5, 4;,
       3;7, 5, 6;,
       3;10, 9, 8;,
       3;11, 9, 10;,
       3;14, 13, 12;,
       3;15, 13, 14;,
       3;18, 17, 16;,
       3;19, 17, 18;,
       3;22, 21, 20;,
       3;23, 21, 22;,
       3;26, 25, 24;,
       3;27, 25, 26;,
       3;30, 29, 28;,
       3;31, 29, 30;,
       3;34, 33, 32;,
       3;35, 33, 34;,
       3;38, 37, 36;,
       3;39, 37, 38;,
       3;42, 41, 40;,
       3;43, 41, 42;,
       3;46, 45, 44;,
       3;47, 45, 46;,
       3;50, 49, 48;,
       3;51, 49, 50;,
       3;54, 53, 52;,
       3;55, 53, 54;,
       3;58, 57, 56;,
       3;59, 57, 58;,
       3;62, 61, 60;,
       3;63, 61, 62;,
       3;66, 65, 64;,
       3;67, 65, 66;,
       3;70, 69, 68;,
       3;71, 69, 70;,
       3;74, 73, 72;,
       3;75, 73, 74;,
       3;78, 77, 76;,
       3;79, 77, 78;,
       3;82, 81, 80;,
       3;82, 83, 81;,
       3;84, 83, 82;,
       3;85, 83, 84;,
       3;88, 87, 86;,
       3;89, 87, 88;,
       3;89, 90, 87;,
       3;89, 91, 90;,
       3;94, 93, 92;,
       3;95, 93, 94;,
       3;98, 97, 96;,
       3;98, 99, 97;,
       3;98, 100, 99;,
       3;98, 101, 100;,
       3;104, 103, 102;,
       3;104, 105, 103;,
       3;104, 106, 105;,
       3;104, 107, 106;;
      }

      MeshTextureCoords {
       108;
       0.163452; 0.142700;,
       0.163452; 0.148071;,
       0.345703; 0.142700;,
       0.345703; 0.148071;,
       0.163452; 0.154419;,
       0.345703; 0.154419;,
       0.163452; 0.148071;,
       0.345703; 0.148071;,
       0.656738; 0.024719;,
       0.042877; 0.024719;,
       0.656738; 0.027466;,
       0.042877; 0.027466;,
       0.656738; 0.030716;,
       0.042877; 0.030716;,
       0.656738; 0.033447;,
       0.042877; 0.033447;,
       0.047577; 0.023758;,
       0.047577; 0.034088;,
       0.661621; 0.023758;,
       0.661621; 0.034088;,
       0.656738; 0.030716;,
       0.656738; 0.027466;,
       0.042877; 0.030716;,
       0.042877; 0.027466;,
       0.610352; 0.099243;,
       0.610352; 0.081787;,
       0.045990; 0.099243;,
       0.045990; 0.081787;,
       0.042877; 0.038666;,
       0.656738; 0.038666;,
       0.042877; 0.033447;,
       0.656738; 0.033447;,
       0.030670; 0.161987;,
       0.628906; 0.161987;,
       0.030670; 0.157227;,
       0.628906; 0.157227;,
       0.030670; 0.150513;,
       0.628906; 0.150513;,
       0.030670; 0.145752;,
       0.628906; 0.145752;,
       0.030670; 0.161987;,
       0.030670; 0.171997;,
       0.628906; 0.161987;,
       0.628906; 0.171997;,
       0.610352; 0.081787;,
       0.045990; 0.081787;,
       0.610352; 0.099243;,
       0.045990; 0.099243;,
       0.030670; 0.150513;,
       0.030670; 0.157227;,
       0.628906; 0.150513;,
       0.628906; 0.157227;,
       0.532227; 0.159790;,
       0.532227; 0.153198;,
       0.131592; 0.159790;,
       0.131592; 0.153198;,
       0.063599; 0.157715;,
       0.275391; 0.157715;,
       0.063599; 0.151123;,
       0.275391; 0.151123;,
       0.063599; 0.157715;,
       0.063599; 0.163086;,
       0.275391; 0.157715;,
       0.275391; 0.163086;,
       0.063599; 0.139282;,
       0.063599; 0.145874;,
       0.275391; 0.139282;,
       0.275391; 0.145874;,
       0.063599; 0.151123;,
       0.275391; 0.151123;,
       0.063599; 0.145874;,
       0.275391; 0.145874;,
       0.163452; 0.159790;,
       0.345703; 0.159790;,
       0.163452; 0.154419;,
       0.345703; 0.154419;,
       0.163452; 0.159790;,
       0.163452; 0.166138;,
       0.345703; 0.159790;,
       0.345703; 0.166138;,
       0.825195; 0.038239;,
       0.846191; 0.038239;,
       0.825195; 0.022522;,
       0.846191; 0.022522;,
       0.830566; 0.017242;,
       0.840820; 0.017242;,
       0.872559; 0.020874;,
       0.872559; 0.033752;,
       0.890137; 0.020874;,
       0.890137; 0.033752;,
       0.877441; 0.038574;,
       0.885254; 0.038574;,
       0.279053; 0.946777;,
       0.914063; 0.946777;,
       0.279053; 0.270752;,
       0.914063; 0.270752;,
       0.958496; 0.109680;,
       0.980469; 0.109680;,
       0.958496; 0.090881;,
       0.980469; 0.090881;,
       0.975098; 0.085327;,
       0.963867; 0.085327;,
       0.991211; 0.058441;,
       0.969238; 0.058441;,
       0.991211; 0.074402;,
       0.969238; 0.074402;,
       0.975586; 0.080383;,
       0.985352; 0.080383;;
      }

      MeshVertexColors {
       108;
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
       107; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       3;
       58;
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
       2,
       2,
       2,
       2,
       2,
       2,
       2,
       2;

       Material M_fenceMetal_Light {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "stainless.jpg";
        }
       }

       Material M_Fence_Light_Mask {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_wiregrid_Tile.tga";
        }
       }

       Material m_blackunlit_INST {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "stainless.jpg";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "sm_fence128_Light";
       108;
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
       107;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {sm_fence128_Light}

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
