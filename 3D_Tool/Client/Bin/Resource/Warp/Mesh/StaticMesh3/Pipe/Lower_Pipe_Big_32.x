xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Thu May 18 11:59:44 2017

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

Frame SceneRoot0 {
  FrameTransformMatrix {
   1.000000, 0.000000, -0.000000, 0.000000,
   0.000000, 1.000000, -0.000000, 0.000000,
   -0.000000, -0.000000, 1.000000, 0.000000,
   0.000000, 0.000000, -0.000000, 1.000000;;
  }

   Frame SceneRoot {
      FrameTransformMatrix {
       1.000000, 0.000000, -0.000000, 0.000000,
       0.000000, 1.000000, -0.000000, 0.000000,
       -0.000000, -0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, -0.000000, 1.000000;;
      }

      Frame Lower_Pipe_Big_32 {
         FrameTransformMatrix {
          1.000000, 0.000000, 0.000000, 0.000000,
          0.000000, -0.000000, 1.000000, 0.000000,
          -0.000000, -1.000000, -0.000000, 0.000000,
          0.000000, 0.000000, -0.000000, 1.000000;;
         }

      }
      Frame Body {
         FrameTransformMatrix {
          1.000000, 0.000000, -0.000000, 0.000000,
          0.000000, 1.000000, -0.000000, 0.000000,
          -0.000000, -0.000000, 1.000000, 0.000000,
          0.000000, 0.000000, -0.000000, 1.000000;;
         }

      }
   }

   Frame Body0 {
      FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

      Mesh skinnedMesh {
       52;
       5.847171; 6.789542; 6.789543;,
       5.847171; 9.601863; -0.000000;,
       5.847171; 0.000000; 9.601863;,
       5.847171; 6.789543; -6.789543;,
       5.847171; 0.000000; -9.601863;,
       5.847171; -9.601863; -0.000000;,
       5.847171; -6.789543; 6.789543;,
       5.847171; -6.789543; -6.789543;,
       0.000000; 9.601863; -0.000000;,
       0.000000; 0.000000; -9.601863;,
       0.000000; 6.789543; -6.789543;,
       0.000000; -9.601863; -0.000000;,
       0.000000; -6.789543; -6.789543;,
       0.000000; 0.000000; 9.601863;,
       0.000000; 6.789542; 6.789543;,
       0.000000; -6.789543; 6.789543;,
       5.847171; 6.789542; 6.789543;,
       5.847171; 0.000000; 9.601863;,
       0.000000; 6.789542; 6.789543;,
       0.000000; 0.000000; 9.601863;,
       5.847171; -6.789543; 6.789543;,
       0.000000; -6.789543; 6.789543;,
       5.847171; -9.601863; -0.000000;,
       0.000000; -9.601863; -0.000000;,
       5.847171; -6.789543; -6.789543;,
       0.000000; -6.789543; -6.789543;,
       5.847171; 0.000000; -9.601863;,
       0.000000; 0.000000; -9.601863;,
       5.847171; 6.789543; -6.789543;,
       0.000000; 6.789543; -6.789543;,
       5.847171; 9.601863; -0.000000;,
       0.000000; 9.601863; -0.000000;,
       5.847171; 6.789542; 6.789543;,
       0.000000; 6.789542; 6.789543;,
       5.847171; 0.000000; -8.197875;,
       31.999998; 5.796769; -5.796772;,
       5.847171; 5.796769; -5.796772;,
       31.999998; 0.000000; -8.197875;,
       5.847171; -5.796769; -5.796775;,
       31.999998; -5.796769; -5.796775;,
       5.847171; -8.197867; -0.000008;,
       31.999998; -8.197867; -0.000008;,
       5.847171; -5.796769; 5.796772;,
       31.999998; -8.197867; -0.000008;,
       5.847171; -8.197867; -0.000008;,
       31.999998; -5.796769; 5.796772;,
       5.847171; 0.000000; 8.197867;,
       31.999998; 0.000000; 8.197867;,
       5.847171; 5.796768; 5.796772;,
       31.999998; 5.796768; 5.796772;,
       5.847171; 8.197869; -0.000000;,
       31.999998; 8.197869; -0.000000;;
       44;
       3;2, 1, 0;,
       3;1, 4, 3;,
       3;2, 4, 1;,
       3;2, 5, 4;,
       3;5, 2, 6;,
       3;4, 5, 7;,
       3;10, 9, 8;,
       3;12, 11, 9;,
       3;9, 11, 13;,
       3;8, 9, 13;,
       3;14, 8, 13;,
       3;11, 15, 13;,
       3;18, 17, 16;,
       3;19, 17, 18;,
       3;19, 20, 17;,
       3;21, 20, 19;,
       3;21, 22, 20;,
       3;23, 22, 21;,
       3;23, 24, 22;,
       3;25, 24, 23;,
       3;25, 26, 24;,
       3;27, 26, 25;,
       3;27, 28, 26;,
       3;29, 28, 27;,
       3;29, 30, 28;,
       3;31, 30, 29;,
       3;31, 32, 30;,
       3;33, 32, 31;,
       3;36, 35, 34;,
       3;34, 35, 37;,
       3;34, 37, 38;,
       3;38, 37, 39;,
       3;38, 39, 40;,
       3;40, 39, 41;,
       3;44, 43, 42;,
       3;42, 43, 45;,
       3;42, 45, 46;,
       3;46, 45, 47;,
       3;46, 47, 48;,
       3;48, 47, 49;,
       3;48, 49, 50;,
       3;50, 49, 51;,
       3;50, 51, 36;,
       3;36, 51, 35;;

      MeshNormals {
       52;
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       0.000000; 0.382683; 0.923880;,
       0.000000; 0.136774; 0.990602;,
       0.000000; 0.382683; 0.923880;,
       0.000000; -0.136774; 0.990602;,
       0.000000; -0.603748; 0.797175;,
       0.000000; -0.797175; 0.603748;,
       0.000000; -0.990602; 0.136774;,
       0.000000; -0.990602; -0.136774;,
       0.000000; -0.797175; -0.603748;,
       0.000000; -0.603748; -0.797175;,
       0.000000; -0.136774; -0.990602;,
       0.000000; 0.136774; -0.990602;,
       0.000000; 0.603748; -0.797175;,
       0.000000; 0.797175; -0.603748;,
       0.000000; 0.990602; -0.136774;,
       0.000000; 0.990602; 0.136774;,
       0.000000; 0.923880; 0.382684;,
       0.000000; 0.923880; 0.382684;,
       0.000000; 0.136774; -0.990602;,
       0.000000; 0.603748; -0.797175;,
       0.000000; 0.797175; -0.603748;,
       0.000000; -0.136773; -0.990602;,
       0.000000; -0.603748; -0.797175;,
       0.000000; -0.797175; -0.603748;,
       0.000000; -0.923880; -0.382683;,
       0.000000; -0.923880; -0.382683;,
       0.000000; -0.797175; 0.603748;,
       0.000000; -0.923880; 0.382683;,
       0.000000; -0.923880; 0.382683;,
       0.000000; -0.603748; 0.797175;,
       0.000000; -0.136773; 0.990602;,
       0.000000; 0.136773; 0.990602;,
       0.000000; 0.603748; 0.797175;,
       0.000000; 0.797175; 0.603748;,
       0.000000; 0.990602; 0.136774;,
       0.000000; 0.990602; -0.136774;;
       44;
       3;2, 1, 0;,
       3;1, 4, 3;,
       3;2, 4, 1;,
       3;2, 5, 4;,
       3;5, 2, 6;,
       3;4, 5, 7;,
       3;10, 9, 8;,
       3;12, 11, 9;,
       3;9, 11, 13;,
       3;8, 9, 13;,
       3;14, 8, 13;,
       3;11, 15, 13;,
       3;18, 17, 16;,
       3;19, 17, 18;,
       3;19, 20, 17;,
       3;21, 20, 19;,
       3;21, 22, 20;,
       3;23, 22, 21;,
       3;23, 24, 22;,
       3;25, 24, 23;,
       3;25, 26, 24;,
       3;27, 26, 25;,
       3;27, 28, 26;,
       3;29, 28, 27;,
       3;29, 30, 28;,
       3;31, 30, 29;,
       3;31, 32, 30;,
       3;33, 32, 31;,
       3;36, 35, 34;,
       3;34, 35, 37;,
       3;34, 37, 38;,
       3;38, 37, 39;,
       3;38, 39, 40;,
       3;40, 39, 41;,
       3;44, 43, 42;,
       3;42, 43, 45;,
       3;42, 45, 46;,
       3;46, 45, 47;,
       3;46, 47, 48;,
       3;48, 47, 49;,
       3;48, 49, 50;,
       3;50, 49, 51;,
       3;50, 51, 36;,
       3;36, 51, 35;;
      }

      MeshTextureCoords {
       52;
       0.814453; 0.725586;,
       0.706543; 0.681152;,
       0.858887; 0.833496;,
       0.599121; 0.725586;,
       0.554688; 0.833496;,
       0.706543; 0.985352;,
       0.814453; 0.940918;,
       0.599121; 0.940918;,
       0.706543; 0.681152;,
       0.554688; 0.833496;,
       0.599121; 0.725586;,
       0.706543; 0.985352;,
       0.599121; 0.940918;,
       0.858887; 0.833496;,
       0.814453; 0.725586;,
       0.814453; 0.940918;,
       0.984863; 0.984863;,
       0.984863; 0.935547;,
       0.888672; 0.984863;,
       0.888672; 0.935547;,
       0.984863; 0.886230;,
       0.888672; 0.886230;,
       0.984863; 0.837402;,
       0.888672; 0.837402;,
       0.984863; 0.788086;,
       0.888672; 0.788086;,
       0.984863; 0.739258;,
       0.888672; 0.739258;,
       0.984863; 0.689941;,
       0.888672; 0.689941;,
       0.984863; 0.640625;,
       0.888672; 0.640625;,
       0.984863; 0.591797;,
       0.888672; 0.591797;,
       0.334717; 0.000031;,
       0.365967; 0.202393;,
       0.365967; 0.000031;,
       0.334717; 0.202393;,
       0.303467; 0.000031;,
       0.303467; 0.202393;,
       0.272217; 0.000031;,
       0.272217; 0.202393;,
       0.490967; 0.000031;,
       0.521973; 0.202393;,
       0.521973; 0.000031;,
       0.490967; 0.202393;,
       0.459717; 0.000031;,
       0.459717; 0.202393;,
       0.428467; 0.000031;,
       0.428467; 0.202393;,
       0.397217; 0.000031;,
       0.397217; 0.202393;;
      }

      FVFData {
       258;
       104;
       1058430976,
       1058250752,
       1054040064,
       1057038336,
       1059643392,
       1061175296,
       1047797760,
       1058250752,
       1042948096,
       1061175296,
       1054040064,
       1065320448,
       1058430976,
       1064108032,
       1047797760,
       1064108032,
       1061175296,
       1041383424,
       1065312256,
       1053261824,
       1064099840,
       1046241280,
       1061175296,
       1059250176,
       1064099840,
       1058037760,
       1057030144,
       1053261824,
       1058242560,
       1046241280,
       1058242560,
       1058037760,
       1042440192,
       1065295872,
       1042440192,
       1063960576,
       990019584,
       1065295872,
       990019584,
       1063960576,
       1042440192,
       1062625280,
       990019584,
       1062625280,
       1042440192,
       1061281792,
       990019584,
       1061281792,
       1042440192,
       1059946496,
       990019584,
       1059946496,
       1042440192,
       1058611200,
       990019584,
       1058611200,
       1042440192,
       1057275904,
       990019584,
       1057275904,
       1042440192,
       1054908416,
       990019584,
       1054908416,
       1042440192,
       1052237824,
       990019584,
       1052237824,
       1056784384,
       1045094400,
       1042948096,
       1048502272,
       1056784384,
       1048502272,
       1042948096,
       1045094400,
       1056784384,
       1041694720,
       1042948096,
       1041694720,
       1056784384,
       1036394496,
       1042948096,
       1036394496,
       1056784384,
       1055342592,
       1042948096,
       1057005568,
       1056784384,
       1057005568,
       1042948096,
       1055342592,
       1056784384,
       1053638656,
       1042948096,
       1053638656,
       1056784384,
       1051942912,
       1042948096,
       1051942912,
       1056784384,
       1050238976,
       1042948096,
       1050238976;
      }

      MeshVertexColors {
       52;
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
       51; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       44;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
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

       Material M_Lower_Pipes {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_Lower_Pipes_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "Lower_Pipe_Big_32";
       52;
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
       51;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
          1.000000, 0.000000, -0.000000, 0.000000,
          -0.000000, -0.000000, -1.000000, 0.000000,
          -0.000000, 1.000000, -0.000000, 0.000000,
          -0.000000, -0.000000, 0.000000, 1.000000;;
      }


     }
   }
}

// Start of Animation

AnimationSet Take_001 {
   Animation {
      {Lower_Pipe_Big_32}

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
