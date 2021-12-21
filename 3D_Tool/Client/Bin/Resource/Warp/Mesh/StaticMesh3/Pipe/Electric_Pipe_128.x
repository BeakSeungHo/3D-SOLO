xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Thu May 18 11:58:49 2017

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

      Frame Electric_Pipe_128 {
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
       56;
       5.847168; 2.649086; 2.649082;,
       5.847168; 3.746372; 0.000001;,
       5.847168; 0.000003; 3.744273;,
       5.847168; 2.647603; -2.647598;,
       5.847168; 0.000003; -3.744273;,
       5.847168; -3.744274; 0.000001;,
       5.847168; -2.647603; 2.647598;,
       5.847168; -2.647603; -2.647598;,
       0.000015; 0.000003; 3.744273;,
       0.000015; 3.746372; 0.000001;,
       0.000015; 2.649086; 2.649082;,
       0.000000; -2.647603; 2.647598;,
       0.000015; -3.744274; 0.000001;,
       0.000015; 0.000003; -3.744273;,
       0.000015; 2.647603; -2.647598;,
       0.000000; -2.647603; -2.647598;,
       5.847168; 2.649086; 2.649082;,
       5.847168; 0.000003; 3.744273;,
       0.000015; 2.649086; 2.649082;,
       0.000015; 0.000003; 3.744273;,
       5.847168; -2.647603; 2.647598;,
       0.000000; -2.647603; 2.647598;,
       5.847168; -1.925435; 1.925441;,
       128.000015; -2.722979; -0.000000;,
       5.847168; -2.722979; -0.000000;,
       128.000015; -1.925435; 1.925441;,
       5.847168; 0.000005; 2.722980;,
       127.999992; 0.000005; 2.722980;,
       5.847168; 1.925436; 1.925440;,
       127.999992; 1.925436; 1.925440;,
       5.847168; -2.647603; 2.647598;,
       5.847168; -3.744274; 0.000001;,
       0.000000; -2.647603; 2.647598;,
       0.000015; -3.744274; 0.000001;,
       5.847168; -2.647603; -2.647598;,
       0.000000; -2.647603; -2.647598;,
       5.847168; 0.000003; -3.744273;,
       0.000015; 0.000003; -3.744273;,
       5.847168; 2.647603; -2.647598;,
       0.000015; 2.647603; -2.647598;,
       5.847168; 3.746372; 0.000001;,
       0.000015; 3.746372; 0.000001;,
       5.847168; 2.649086; 2.649082;,
       0.000015; 2.649086; 2.649082;,
       128.000015; -2.722979; -0.000000;,
       128.000015; -1.925435; -1.925441;,
       5.847168; -2.722979; -0.000000;,
       5.847168; -1.925435; -1.925441;,
       127.999992; 0.000005; -2.722980;,
       5.847168; 0.000005; -2.722980;,
       127.999992; 1.925436; -1.925440;,
       5.847168; 1.925436; -1.925440;,
       127.999992; 2.722979; -0.000000;,
       5.847168; 2.722979; -0.000000;,
       127.999992; 1.925436; 1.925440;,
       5.847168; 1.925436; 1.925440;;
       44;
       3;2, 1, 0;,
       3;1, 4, 3;,
       3;2, 4, 1;,
       3;2, 5, 4;,
       3;5, 2, 6;,
       3;4, 5, 7;,
       3;10, 9, 8;,
       3;12, 11, 8;,
       3;13, 12, 8;,
       3;9, 13, 8;,
       3;14, 13, 9;,
       3;15, 12, 13;,
       3;18, 17, 16;,
       3;19, 17, 18;,
       3;19, 20, 17;,
       3;21, 20, 19;,
       3;24, 23, 22;,
       3;22, 23, 25;,
       3;22, 25, 26;,
       3;26, 25, 27;,
       3;26, 27, 28;,
       3;28, 27, 29;,
       3;32, 31, 30;,
       3;33, 31, 32;,
       3;33, 34, 31;,
       3;35, 34, 33;,
       3;35, 36, 34;,
       3;37, 36, 35;,
       3;37, 38, 36;,
       3;39, 38, 37;,
       3;39, 40, 38;,
       3;41, 40, 39;,
       3;41, 42, 40;,
       3;43, 42, 41;,
       3;46, 45, 44;,
       3;47, 45, 46;,
       3;47, 48, 45;,
       3;49, 48, 47;,
       3;49, 50, 48;,
       3;51, 50, 49;,
       3;51, 52, 50;,
       3;53, 52, 51;,
       3;53, 54, 52;,
       3;55, 54, 53;;

      MeshNormals {
       56;
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000002; -0.000002;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000010; -0.000010;,
       -1.000000; 0.000007; -0.000000;,
       -1.000000; 0.000002; 0.000002;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000010; 0.000010;,
       0.000000; 0.382060; 0.924138;,
       0.000000; 0.136311; 0.990666;,
       0.000000; 0.382060; 0.924138;,
       0.000000; -0.136980; 0.990574;,
       0.000000; -0.382684; 0.923880;,
       0.000000; -0.382684; 0.923880;,
       0.000000; -0.797175; 0.603749;,
       0.000000; -0.923880; 0.382684;,
       0.000000; -0.923880; 0.382684;,
       0.000000; -0.603747; 0.797176;,
       0.000000; -0.136772; 0.990602;,
       0.000000; 0.136774; 0.990602;,
       0.000000; 0.382684; 0.923880;,
       0.000000; 0.382684; 0.923880;,
       0.000000; -0.923880; 0.382684;,
       0.000000; -0.990602; 0.136774;,
       0.000000; -0.923880; 0.382684;,
       0.000000; -0.990602; -0.136774;,
       0.000000; -0.797175; -0.603748;,
       0.000000; -0.603748; -0.797175;,
       0.000000; -0.136773; -0.990602;,
       0.000000; 0.136774; -0.990602;,
       0.000000; 0.603582; -0.797301;,
       0.000000; 0.796893; -0.604120;,
       0.000000; 0.990538; -0.137237;,
       0.000000; 0.990631; 0.136567;,
       0.000000; 0.923879; 0.382684;,
       0.000000; 0.923879; 0.382684;,
       0.000000; -0.923880; -0.382684;,
       0.000000; -0.797175; -0.603749;,
       0.000000; -0.923880; -0.382684;,
       0.000000; -0.603747; -0.797176;,
       0.000000; -0.136772; -0.990602;,
       0.000000; 0.136774; -0.990602;,
       0.000000; 0.603748; -0.797175;,
       0.000000; 0.797175; -0.603748;,
       0.000000; 0.990602; -0.136774;,
       0.000000; 0.990602; 0.136774;,
       0.000000; 0.923880; 0.382683;,
       0.000000; 0.923880; 0.382683;;
       44;
       3;2, 1, 0;,
       3;1, 4, 3;,
       3;2, 4, 1;,
       3;2, 5, 4;,
       3;5, 2, 6;,
       3;4, 5, 7;,
       3;10, 9, 8;,
       3;12, 11, 8;,
       3;13, 12, 8;,
       3;9, 13, 8;,
       3;14, 13, 9;,
       3;15, 12, 13;,
       3;18, 17, 16;,
       3;19, 17, 18;,
       3;19, 20, 17;,
       3;21, 20, 19;,
       3;24, 23, 22;,
       3;22, 23, 25;,
       3;22, 25, 26;,
       3;26, 25, 27;,
       3;26, 27, 28;,
       3;28, 27, 29;,
       3;32, 31, 30;,
       3;33, 31, 32;,
       3;33, 34, 31;,
       3;35, 34, 33;,
       3;35, 36, 34;,
       3;37, 36, 35;,
       3;37, 38, 36;,
       3;39, 38, 37;,
       3;39, 40, 38;,
       3;41, 40, 39;,
       3;41, 42, 40;,
       3;43, 42, 41;,
       3;46, 45, 44;,
       3;47, 45, 46;,
       3;47, 48, 45;,
       3;49, 48, 47;,
       3;49, 50, 48;,
       3;51, 50, 49;,
       3;51, 52, 50;,
       3;53, 52, 51;,
       3;53, 54, 52;,
       3;55, 54, 53;;
      }

      MeshTextureCoords {
       56;
       0.814453; 0.725586;,
       0.706543; 0.681152;,
       0.858887; 0.833496;,
       0.599121; 0.725586;,
       0.554688; 0.833496;,
       0.706543; 0.985352;,
       0.814453; 0.940918;,
       0.599121; 0.940918;,
       0.858887; 0.833496;,
       0.706543; 0.681152;,
       0.814453; 0.725586;,
       0.814453; 0.940918;,
       0.706543; 0.985352;,
       0.554688; 0.833496;,
       0.599121; 0.725586;,
       0.599121; 0.940918;,
       0.984863; 0.984863;,
       0.984863; 0.935547;,
       0.888672; 0.984863;,
       0.888672; 0.935547;,
       0.984863; 0.886230;,
       0.888672; 0.886230;,
       0.490967; 0.341309;,
       0.521973; 0.998535;,
       0.521973; 0.341309;,
       0.490967; 0.998535;,
       0.459717; 0.341309;,
       0.459717; 0.998535;,
       0.428467; 0.341309;,
       0.428467; 0.998535;,
       0.984863; 0.886230;,
       0.984863; 0.837402;,
       0.888672; 0.886230;,
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
       0.272217; 0.998535;,
       0.303467; 0.998535;,
       0.272217; 0.341309;,
       0.303467; 0.341309;,
       0.334717; 0.998535;,
       0.334717; 0.341309;,
       0.365967; 0.998535;,
       0.365967; 0.341309;,
       0.397217; 0.998535;,
       0.397217; 0.341309;,
       0.428467; 0.998535;,
       0.428467; 0.341309;;
      }

      FVFData {
       258;
       112;
       1054081024,
       1060610048,
       1057595392,
       1061470208,
       1052368896,
       1058545664,
       1059659776,
       1060610048,
       1060519936,
       1058545664,
       1057595392,
       1054269440,
       1054081024,
       1055981568,
       1059659776,
       1055981568,
       1052368896,
       1046544384,
       1057595392,
       1027170304,
       1054081024,
       1036345344,
       1054081024,
       1051697152,
       1057595392,
       1053417472,
       1060519936,
       1046544384,
       1059659776,
       1036345344,
       1059659776,
       1051697152,
       1064214528,
       1047650304,
       1064214528,
       1039581184,
       1061412864,
       1047650304,
       1061412864,
       1039581184,
       1064214528,
       1000136704,
       1061412864,
       1000136704,
       1034829824,
       990019584,
       1040195584,
       1065312256,
       1040195584,
       990019584,
       1034829824,
       1065312256,
       1027088384,
       990019584,
       1027088384,
       1065312256,
       1000243200,
       990019584,
       1000235008,
       1065312256,
       1064214528,
       1064181760,
       1064214528,
       1062240256,
       1061412864,
       1064181760,
       1061412864,
       1062240256,
       1064214528,
       1060298752,
       1061412864,
       1060298752,
       1064214528,
       1058357248,
       1061412864,
       1058357248,
       1064214528,
       1055875072,
       1061412864,
       1055875072,
       1064214528,
       1051992064,
       1061412864,
       1051992064,
       1064214528,
       1047650304,
       1061412864,
       1047650304,
       1040195584,
       1065312256,
       1042890752,
       1065312256,
       1040195584,
       990019584,
       1042890752,
       990019584,
       1045585920,
       1065312256,
       1045585920,
       990019584,
       1048281088,
       1065312256,
       1048272896,
       990019584,
       1049772032,
       1065312256,
       1049772032,
       990019584,
       1051115520,
       1065312256,
       1051115520,
       990019584;
      }

      MeshVertexColors {
       56;
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
       55; 1.000000; 1.000000; 1.000000; 1.000000;;
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

       Material M_Electric_Pipes_INST {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_Upper_Pipes_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "Electric_Pipe_128";
       56;
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
       55;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {Electric_Pipe_128}

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