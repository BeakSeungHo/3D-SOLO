xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Sun May 14 19:14:42 2017

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

   Frame framing_3x2y2z {
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
       112;
       0.000000; -0.000000; 128.000000;,
       1.146973; 7.999886; 120.000000;,
       1.146973; 7.999889; 7.999996;,
       0.000000; 0.000000; 0.000000;,
       0.000000; 0.000000; 0.000000;,
       8.000015; 2.062294; 8.000011;,
       8.000015; 2.062294; 120.000000;,
       0.000000; -0.000000; 128.000000;,
       192.000000; 128.000000; 0.000000;,
       184.000000; 126.627808; 8.000019;,
       184.000000; 126.627808; 120.000000;,
       192.000000; 128.000000; 128.000000;,
       192.000000; 0.000000; 0.000000;,
       190.777588; 7.999889; 7.999996;,
       190.777588; 7.999886; 120.000000;,
       192.000000; -0.000000; 128.000000;,
       184.000000; 2.062294; 120.000000;,
       192.000000; -0.000000; 128.000000;,
       0.000000; -0.000000; 128.000000;,
       8.000015; 2.062294; 120.000000;,
       192.000000; 128.000000; 128.000000;,
       184.000000; 126.627808; 120.000000;,
       8.000015; 126.627800; 120.000000;,
       0.000000; 128.000000; 128.000000;,
       192.000000; -0.000000; 128.000000;,
       184.000000; 7.999886; 126.305420;,
       8.000015; 7.999886; 126.305420;,
       0.000000; -0.000000; 128.000000;,
       192.000000; 0.000000; 0.000000;,
       184.000000; 2.062294; 8.000019;,
       8.000015; 2.062294; 8.000011;,
       0.000000; 0.000000; 0.000000;,
       0.000000; 128.000000; 0.000000;,
       0.000000; 128.000000; 128.000000;,
       8.000015; 126.627800; 120.000000;,
       8.000015; 126.627800; 8.000011;,
       0.000000; 0.000000; 0.000000;,
       8.000015; 7.999889; 1.919189;,
       184.000000; 7.999889; 1.919189;,
       192.000000; 0.000000; 0.000000;,
       0.000000; 128.000000; 0.000000;,
       8.000015; 126.627800; 8.000011;,
       184.000000; 126.627808; 8.000019;,
       192.000000; 128.000000; 0.000000;,
       192.000000; 0.000000; 0.000000;,
       192.000000; -0.000000; 128.000000;,
       184.000000; 2.062294; 120.000000;,
       184.000000; 2.062294; 8.000019;,
       0.000000; 128.000000; 128.000000;,
       0.000000; 128.000000; 0.000000;,
       1.146973; 119.999901; 8.000004;,
       1.146973; 119.999893; 120.000000;,
       192.000000; 128.000000; 0.000000;,
       192.000000; 128.000000; 128.000000;,
       190.777588; 119.999893; 120.000000;,
       190.777588; 119.999901; 8.000004;,
       192.000000; 128.000000; 128.000000;,
       0.000000; 128.000000; 128.000000;,
       8.000015; 119.999893; 126.305420;,
       184.000000; 119.999886; 126.305420;,
       0.000000; 128.000000; 0.000000;,
       192.000000; 128.000000; 0.000000;,
       184.000000; 119.999886; 1.919189;,
       8.000000; 119.999886; 1.919197;,
       8.000015; 119.999893; 126.305420;,
       0.000000; 128.000000; 128.000000;,
       0.000000; -0.000000; 128.000000;,
       8.000015; 7.999886; 126.305420;,
       190.777588; 119.999893; 120.000000;,
       192.000000; 128.000000; 128.000000;,
       192.000000; -0.000000; 128.000000;,
       190.777588; 7.999886; 120.000000;,
       184.000000; 119.999886; 1.919189;,
       192.000000; 128.000000; 0.000000;,
       192.000000; 0.000000; 0.000000;,
       184.000000; 7.999889; 1.919189;,
       1.146973; 119.999901; 8.000004;,
       0.000000; 128.000000; 0.000000;,
       0.000000; 0.000000; 0.000000;,
       1.146973; 7.999889; 7.999996;,
       192.000000; 128.000000; 0.000000;,
       190.777588; 119.999901; 8.000004;,
       190.777588; 7.999889; 7.999996;,
       192.000000; 0.000000; 0.000000;,
       0.000000; 128.000000; 128.000000;,
       1.146973; 119.999893; 120.000000;,
       1.146973; 7.999886; 120.000000;,
       0.000000; -0.000000; 128.000000;,
       0.000000; 128.000000; 0.000000;,
       8.000000; 119.999886; 1.919197;,
       8.000015; 7.999889; 1.919189;,
       0.000000; 0.000000; 0.000000;,
       192.000000; 128.000000; 128.000000;,
       184.000000; 119.999886; 126.305420;,
       184.000000; 7.999886; 126.305420;,
       192.000000; -0.000000; 128.000000;,
       191.246216; 8.146751; 126.172516;,
       7.246269; 127.246170; 126.172516;,
       0.753731; 120.753723; 126.172516;,
       184.753769; 1.654213; 126.172516;,
       7.246269; 127.246178; 1.827488;,
       191.246216; 8.146751; 1.827488;,
       184.753769; 1.654221; 1.827492;,
       0.753731; 120.753723; 1.827496;,
       191.246216; 2.277706; 7.696529;,
       7.246269; 2.277710; 126.795952;,
       0.753731; 2.277710; 120.303505;,
       184.753769; 2.277706; 1.203991;,
       7.246269; 126.622726; 126.795959;,
       191.246216; 126.622726; 7.696533;,
       184.753769; 126.622726; 1.204002;,
       0.753731; 126.622726; 120.303513;;
       56;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 5, 6;,
       3;6, 7, 4;,
       3;8, 9, 10;,
       3;10, 11, 8;,
       3;12, 13, 14;,
       3;14, 15, 12;,
       3;16, 17, 18;,
       3;18, 19, 16;,
       3;20, 21, 22;,
       3;22, 23, 20;,
       3;24, 25, 26;,
       3;26, 27, 24;,
       3;28, 29, 30;,
       3;30, 31, 28;,
       3;32, 33, 34;,
       3;34, 35, 32;,
       3;36, 37, 38;,
       3;38, 39, 36;,
       3;40, 41, 42;,
       3;42, 43, 40;,
       3;44, 45, 46;,
       3;46, 47, 44;,
       3;48, 49, 50;,
       3;50, 51, 48;,
       3;52, 53, 54;,
       3;54, 55, 52;,
       3;56, 57, 58;,
       3;58, 59, 56;,
       3;60, 61, 62;,
       3;62, 63, 60;,
       3;64, 65, 66;,
       3;66, 67, 64;,
       3;68, 69, 70;,
       3;70, 71, 68;,
       3;72, 73, 74;,
       3;74, 75, 72;,
       3;76, 77, 78;,
       3;78, 79, 76;,
       3;80, 81, 82;,
       3;82, 83, 80;,
       3;84, 85, 86;,
       3;86, 87, 84;,
       3;88, 89, 90;,
       3;90, 91, 88;,
       3;92, 93, 94;,
       3;94, 95, 92;,
       3;96, 97, 98;,
       3;98, 99, 96;,
       3;100, 101, 102;,
       3;102, 103, 100;,
       3;104, 105, 106;,
       3;106, 107, 104;,
       3;108, 109, 110;,
       3;110, 111, 108;;

      MeshNormals {
       112;
       -0.989878; 0.141922; 0.000000;,
       -0.989878; 0.141922; 0.000000;,
       -0.989878; 0.141922; 0.000000;,
       -0.989878; 0.141922; 0.000000;,
       0.249625; -0.968342; 0.000000;,
       0.249625; -0.968342; 0.000000;,
       0.249625; -0.968342; 0.000000;,
       0.249625; -0.968342; 0.000000;,
       -0.169055; 0.985607; 0.000000;,
       -0.169055; 0.985607; 0.000000;,
       -0.169055; 0.985607; 0.000000;,
       -0.169055; 0.985607; 0.000000;,
       0.988526; 0.151050; 0.000000;,
       0.988526; 0.151050; 0.000000;,
       0.988526; 0.151050; 0.000000;,
       0.988526; 0.151050; 0.000000;,
       0.000000; -0.968342; -0.249626;,
       0.000000; -0.968342; -0.249626;,
       0.000000; -0.968342; -0.249626;,
       0.000000; -0.968342; -0.249626;,
       -0.000000; 0.985607; -0.169056;,
       -0.000000; 0.985607; -0.169055;,
       -0.000000; 0.985607; -0.169056;,
       0.000000; 0.985606; -0.169056;,
       0.000000; 0.207227; 0.978293;,
       0.000000; 0.207227; 0.978293;,
       0.000000; 0.207227; 0.978293;,
       0.000000; 0.207227; 0.978293;,
       -0.000000; -0.968343; 0.249625;,
       -0.000000; -0.968343; 0.249625;,
       -0.000000; -0.968343; 0.249625;,
       0.000000; -0.968343; 0.249625;,
       0.169056; 0.985607; 0.000000;,
       0.169056; 0.985606; 0.000000;,
       0.169056; 0.985607; 0.000000;,
       0.169056; 0.985607; 0.000000;,
       0.000000; 0.233283; -0.972409;,
       0.000000; 0.233283; -0.972409;,
       0.000000; 0.233283; -0.972409;,
       0.000000; 0.233283; -0.972409;,
       -0.000000; 0.985607; 0.169055;,
       -0.000000; 0.985607; 0.169056;,
       -0.000000; 0.985607; 0.169055;,
       0.000000; 0.985607; 0.169055;,
       -0.249626; -0.968342; -0.000000;,
       -0.249626; -0.968342; -0.000000;,
       -0.249626; -0.968342; -0.000000;,
       -0.249626; -0.968342; 0.000000;,
       -0.989878; -0.141919; -0.000000;,
       -0.989878; -0.141919; 0.000000;,
       -0.989878; -0.141919; -0.000000;,
       -0.989878; -0.141919; -0.000000;,
       0.988527; -0.151046; -0.000000;,
       0.988527; -0.151046; 0.000000;,
       0.988527; -0.151046; -0.000000;,
       0.988527; -0.151046; -0.000000;,
       -0.000000; -0.207222; 0.978294;,
       0.000000; -0.207222; 0.978294;,
       -0.000000; -0.207222; 0.978294;,
       -0.000000; -0.207222; 0.978294;,
       -0.000000; -0.233277; -0.972410;,
       0.000000; -0.233277; -0.972410;,
       -0.000000; -0.233277; -0.972410;,
       -0.000000; -0.233278; -0.972410;,
       0.207224; 0.000000; 0.978293;,
       0.207224; 0.000000; 0.978293;,
       0.207224; 0.000000; 0.978293;,
       0.207224; 0.000000; 0.978293;,
       0.988526; 0.000000; -0.151048;,
       0.988526; 0.000000; -0.151048;,
       0.988526; 0.000000; -0.151048;,
       0.988526; 0.000000; -0.151048;,
       -0.233280; 0.000000; -0.972410;,
       -0.233280; 0.000000; -0.972410;,
       -0.233280; 0.000000; -0.972410;,
       -0.233280; 0.000000; -0.972410;,
       -0.989878; -0.000000; 0.141920;,
       -0.989878; 0.000000; 0.141920;,
       -0.989878; -0.000000; 0.141920;,
       -0.989878; -0.000000; 0.141920;,
       0.988526; -0.000000; 0.151048;,
       0.988526; -0.000000; 0.151048;,
       0.988526; -0.000000; 0.151048;,
       0.988526; 0.000000; 0.151048;,
       -0.989878; 0.000000; -0.141920;,
       -0.989878; 0.000000; -0.141920;,
       -0.989878; 0.000000; -0.141920;,
       -0.989878; 0.000000; -0.141920;,
       0.233280; 0.000000; -0.972410;,
       0.233281; 0.000000; -0.972409;,
       0.233280; 0.000000; -0.972410;,
       0.233279; 0.000000; -0.972410;,
       -0.207225; 0.000000; 0.978293;,
       -0.207225; 0.000000; 0.978293;,
       -0.207225; 0.000000; 0.978293;,
       -0.207225; 0.000000; 0.978293;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.000000; 1.000000;,
       -0.000000; -0.000001; -1.000000;,
       -0.000000; -0.000000; -1.000000;,
       -0.000000; -0.000001; -1.000000;,
       -0.000000; -0.000001; -1.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;;
       56;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 5, 6;,
       3;6, 7, 4;,
       3;8, 9, 10;,
       3;10, 11, 8;,
       3;12, 13, 14;,
       3;14, 15, 12;,
       3;16, 17, 18;,
       3;18, 19, 16;,
       3;20, 21, 22;,
       3;22, 23, 20;,
       3;24, 25, 26;,
       3;26, 27, 24;,
       3;28, 29, 30;,
       3;30, 31, 28;,
       3;32, 33, 34;,
       3;34, 35, 32;,
       3;36, 37, 38;,
       3;38, 39, 36;,
       3;40, 41, 42;,
       3;42, 43, 40;,
       3;44, 45, 46;,
       3;46, 47, 44;,
       3;48, 49, 50;,
       3;50, 51, 48;,
       3;52, 53, 54;,
       3;54, 55, 52;,
       3;56, 57, 58;,
       3;58, 59, 56;,
       3;60, 61, 62;,
       3;62, 63, 60;,
       3;64, 65, 66;,
       3;66, 67, 64;,
       3;68, 69, 70;,
       3;70, 71, 68;,
       3;72, 73, 74;,
       3;74, 75, 72;,
       3;76, 77, 78;,
       3;78, 79, 76;,
       3;80, 81, 82;,
       3;82, 83, 80;,
       3;84, 85, 86;,
       3;86, 87, 84;,
       3;88, 89, 90;,
       3;90, 91, 88;,
       3;92, 93, 94;,
       3;94, 95, 92;,
       3;96, 97, 98;,
       3;98, 99, 96;,
       3;100, 101, 102;,
       3;102, 103, 100;,
       3;104, 105, 106;,
       3;106, 107, 104;,
       3;108, 109, 110;,
       3;110, 111, 108;;
      }

      MeshTextureCoords {
       112;
       0.479736; 0.385986;,
       0.507324; 0.414063;,
       0.897461; 0.414063;,
       0.925293; 0.385986;,
       0.458984; 0.151001;,
       0.431152; 0.123108;,
       0.041168; 0.123108;,
       0.013306; 0.151001;,
       0.486572; 0.178467;,
       0.514160; 0.206299;,
       0.904297; 0.206299;,
       0.932129; 0.178467;,
       0.479736; 0.337646;,
       0.507324; 0.365479;,
       0.897461; 0.365479;,
       0.925293; 0.337646;,
       0.876953; 0.789063;,
       0.904785; 0.761230;,
       0.013306; 0.761230;,
       0.041168; 0.789063;,
       0.904785; 0.886230;,
       0.876953; 0.858398;,
       0.041168; 0.858398;,
       0.013306; 0.886230;,
       0.904785; 0.691895;,
       0.876953; 0.664063;,
       0.041168; 0.664063;,
       0.013306; 0.691895;,
       0.904785; 0.740723;,
       0.876953; 0.712891;,
       0.041168; 0.712891;,
       0.013306; 0.740723;,
       0.013306; 0.261719;,
       0.458984; 0.261719;,
       0.431152; 0.233765;,
       0.041168; 0.233765;,
       0.904785; 0.643555;,
       0.876953; 0.615723;,
       0.041168; 0.615723;,
       0.013306; 0.643555;,
       0.013306; 0.809570;,
       0.041168; 0.837402;,
       0.876953; 0.837402;,
       0.904785; 0.809570;,
       0.932129; 0.123108;,
       0.486572; 0.123108;,
       0.514160; 0.151001;,
       0.904297; 0.151001;,
       0.013306; 0.414063;,
       0.458984; 0.414063;,
       0.431152; 0.385986;,
       0.041168; 0.385986;,
       0.013306; 0.365479;,
       0.458984; 0.365479;,
       0.431152; 0.337646;,
       0.041168; 0.337646;,
       0.904785; 0.955078;,
       0.013306; 0.955078;,
       0.041168; 0.982910;,
       0.876953; 0.982910;,
       0.904785; 0.906738;,
       0.013306; 0.906738;,
       0.041168; 0.934570;,
       0.876953; 0.934570;,
       0.514160; 0.289063;,
       0.486572; 0.316895;,
       0.932129; 0.316895;,
       0.904297; 0.289063;,
       0.431152; 0.316895;,
       0.458984; 0.289063;,
       0.013306; 0.289063;,
       0.041168; 0.316895;,
       0.514160; 0.233765;,
       0.486572; 0.261719;,
       0.932129; 0.261719;,
       0.904297; 0.233765;,
       0.904297; 0.095642;,
       0.932129; 0.067749;,
       0.486572; 0.067749;,
       0.514160; 0.095642;,
       0.458984; 0.206299;,
       0.431152; 0.178467;,
       0.041168; 0.178467;,
       0.013306; 0.206299;,
       0.932129; 0.040253;,
       0.904297; 0.012413;,
       0.514160; 0.012413;,
       0.486572; 0.040253;,
       0.013306; 0.067749;,
       0.041168; 0.095642;,
       0.431152; 0.095642;,
       0.458984; 0.067749;,
       0.013306; 0.012413;,
       0.041168; 0.040253;,
       0.431152; 0.040253;,
       0.458984; 0.012413;,
       0.013306; 0.458252;,
       0.761719; 0.458252;,
       0.770020; 0.434570;,
       0.021576; 0.434570;,
       0.021576; 0.546387;,
       0.770020; 0.546387;,
       0.761719; 0.522949;,
       0.013306; 0.522949;,
       0.013306; 0.502441;,
       0.761719; 0.502441;,
       0.770020; 0.478760;,
       0.021576; 0.478760;,
       0.761719; 0.575684;,
       0.013306; 0.566895;,
       0.021301; 0.595215;,
       0.769531; 0.595215;;
      }

      FVFData {
       258;
       224;
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216,
       0,
       1065353216;
      }

      MeshVertexColors {
       112;
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
       111; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       56;
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

       Material m_framing {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "t_brushed_metal_Black_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "framing_3x2y2z";
       112;
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
       111;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {framing_3x2y2z}

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
