xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Sat May 13 21:38:35 2017

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

   Frame LadderBar {
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
       84;
       20.297304; -2.772367; 2.696970;,
       16.268818; -2.772369; 2.696970;,
       16.268818; -2.772369; -0.000000;,
       20.297304; -2.772367; -0.000000;,
       21.542170; 1.058951; 2.696970;,
       21.542170; 1.058951; 0.000000;,
       18.283056; 3.426836; 2.696970;,
       18.283056; 3.426836; 0.000000;,
       15.023944; 1.058950; 2.696970;,
       15.023944; 1.058950; 0.000000;,
       16.268818; -2.772369; 2.696970;,
       16.268818; -2.772369; -0.000000;,
       -15.496280; -1.660447; 19.510792;,
       15.496277; -1.660447; 19.510792;,
       15.642779; 0.634235; 20.234774;,
       -18.172113; -1.660447; 18.172104;,
       -15.642782; 0.634235; 20.234772;,
       15.259236; 2.052426; 18.339363;,
       17.319063; 2.052426; 17.319065;,
       18.699324; 0.634235; 18.699306;,
       18.172112; -1.660447; 18.172100;,
       -19.510786; -1.660447; 15.496305;,
       -18.699326; 0.634235; 18.699308;,
       -15.259239; 2.052426; 18.339361;,
       14.875693; 0.634234; 16.443951;,
       15.938805; 0.634234; 15.938822;,
       16.443962; 0.634234; 14.875657;,
       18.339361; 2.052426; 15.259237;,
       -19.489445; -1.660447; 2.696970;,
       -20.234762; 0.634235; 15.642819;,
       -17.319065; 2.052426; 17.319065;,
       -14.875696; 0.634234; 16.443951;,
       15.022195; -1.660448; 17.167933;,
       16.466017; -1.660448; 16.466028;,
       17.167940; -1.660448; 15.022172;,
       -15.022198; -1.660448; 17.167933;,
       -16.466019; -1.660448; 16.466030;,
       -15.938807; 0.634234; 15.938822;,
       -17.167940; -1.660448; 15.022172;,
       -16.443962; 0.634234; 14.875656;,
       -18.339361; 2.052426; 15.259238;,
       -17.076672; -1.660448; 2.696970;,
       -16.331083; 0.634234; 2.696970;,
       -18.283056; 2.052426; 2.696970;,
       -20.235029; 0.634235; 2.696970;,
       15.022195; -1.660448; 17.167933;,
       16.466017; -1.660448; 16.466028;,
       -15.022198; -1.660448; 17.167933;,
       -16.466019; -1.660448; 16.466030;,
       -17.167940; -1.660448; 15.022172;,
       -17.076672; -1.660448; 2.696970;,
       20.234762; 0.634235; 15.642817;,
       19.510784; -1.660447; 15.496302;,
       17.167940; -1.660448; 15.022172;,
       17.076672; -1.660448; 2.696970;,
       16.331083; 0.634234; 2.696970;,
       18.283056; 2.052426; 2.696970;,
       20.235029; 0.634235; 2.696970;,
       19.489445; -1.660447; 2.696970;,
       17.076672; -1.660448; 2.696970;,
       18.283056; -0.000000; 4.245556;,
       21.542170; 1.058951; 2.696970;,
       18.283056; 3.426836; 2.696970;,
       15.023944; 1.058950; 2.696970;,
       16.268818; -2.772369; 2.696970;,
       20.297304; -2.772367; 2.696970;,
       -18.283056; -0.000000; 4.245556;,
       -18.283056; 3.426836; 2.696970;,
       -21.542170; 1.058951; 2.696970;,
       -20.297304; -2.772368; 2.696970;,
       -16.268818; -2.772369; 2.696970;,
       -15.023944; 1.058950; 2.696970;,
       -15.023944; 1.058950; 2.696970;,
       -16.268818; -2.772369; 2.696970;,
       -16.268818; -2.772369; -0.000000;,
       -15.023944; 1.058950; 0.000000;,
       -18.283056; 3.426836; 2.696970;,
       -18.283056; 3.426836; 0.000000;,
       -21.542170; 1.058951; 2.696970;,
       -21.542170; 1.058951; 0.000000;,
       -20.297304; -2.772368; 2.696970;,
       -20.297304; -2.772368; -0.000000;,
       -16.268818; -2.772369; 2.696970;,
       -16.268818; -2.772369; -0.000000;;
       100;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 0, 3;,
       3;3, 5, 4;,
       3;6, 4, 5;,
       3;5, 7, 6;,
       3;8, 6, 7;,
       3;7, 9, 8;,
       3;10, 8, 9;,
       3;9, 11, 10;,
       3;12, 13, 14;,
       3;15, 12, 16;,
       3;14, 16, 12;,
       3;16, 14, 17;,
       3;18, 17, 14;,
       3;14, 19, 18;,
       3;19, 14, 13;,
       3;13, 20, 19;,
       3;21, 15, 22;,
       3;16, 22, 15;,
       3;22, 16, 23;,
       3;17, 23, 16;,
       3;23, 17, 24;,
       3;25, 24, 17;,
       3;17, 18, 25;,
       3;26, 25, 18;,
       3;18, 27, 26;,
       3;27, 18, 19;,
       3;28, 21, 29;,
       3;22, 29, 21;,
       3;29, 22, 30;,
       3;23, 30, 22;,
       3;30, 23, 31;,
       3;24, 31, 23;,
       3;31, 24, 32;,
       3;33, 32, 24;,
       3;24, 25, 33;,
       3;34, 33, 25;,
       3;32, 35, 31;,
       3;35, 36, 37;,
       3;37, 31, 35;,
       3;31, 37, 30;,
       3;36, 38, 39;,
       3;39, 37, 36;,
       3;37, 39, 40;,
       3;40, 30, 37;,
       3;30, 40, 29;,
       3;38, 41, 42;,
       3;42, 39, 38;,
       3;39, 42, 43;,
       3;43, 40, 39;,
       3;40, 43, 44;,
       3;44, 29, 40;,
       3;29, 44, 28;,
       3;45, 46, 20;,
       3;20, 13, 45;,
       3;47, 45, 13;,
       3;13, 12, 47;,
       3;48, 47, 12;,
       3;12, 15, 48;,
       3;49, 48, 15;,
       3;15, 21, 49;,
       3;50, 49, 21;,
       3;21, 28, 50;,
       3;19, 51, 27;,
       3;51, 19, 20;,
       3;20, 52, 51;,
       3;52, 20, 46;,
       3;46, 53, 52;,
       3;25, 26, 34;,
       3;54, 34, 26;,
       3;26, 55, 54;,
       3;55, 26, 27;,
       3;27, 56, 55;,
       3;56, 27, 51;,
       3;51, 57, 56;,
       3;57, 51, 52;,
       3;52, 58, 57;,
       3;58, 52, 53;,
       3;53, 59, 58;,
       3;60, 61, 62;,
       3;60, 62, 63;,
       3;60, 63, 64;,
       3;60, 64, 65;,
       3;60, 65, 61;,
       3;66, 67, 68;,
       3;66, 68, 69;,
       3;66, 69, 70;,
       3;66, 70, 71;,
       3;66, 71, 67;,
       3;72, 73, 74;,
       3;74, 75, 72;,
       3;76, 72, 75;,
       3;75, 77, 76;,
       3;78, 76, 77;,
       3;77, 79, 78;,
       3;80, 78, 79;,
       3;79, 81, 80;,
       3;82, 80, 81;,
       3;81, 83, 82;;

      MeshNormals {
       84;
       0.380848; -0.924638; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.761695; -0.647935; 0.000000;,
       0.997071; 0.076479; 0.000000;,
       0.851600; 0.524191; 0.000000;,
       0.235377; 0.971904; 0.000000;,
       -0.235377; 0.971904; 0.000000;,
       -0.851601; 0.524191; 0.000000;,
       -0.997071; 0.076478; 0.000000;,
       -0.951056; -0.309018; 0.000000;,
       -0.951056; -0.309018; 0.000000;,
       -0.089080; -0.812787; 0.575710;,
       0.178675; -0.812156; 0.555407;,
       0.202563; 0.311823; 0.928297;,
       -0.359971; -0.817640; 0.449317;,
       -0.235677; 0.314517; 0.919530;,
       -0.054303; 0.998468; 0.010623;,
       -0.057910; 0.996613; 0.058387;,
       0.653682; 0.319039; 0.686232;,
       0.449316; -0.817640; 0.359971;,
       -0.555453; -0.812195; 0.178356;,
       -0.686231; 0.319039; 0.653682;,
       -0.057000; 0.998309; -0.011428;,
       -0.226657; 0.314584; -0.921772;,
       -0.687624; 0.320799; -0.651353;,
       -0.931420; 0.309279; -0.191841;,
       -0.009133; 0.998272; 0.058054;,
       -0.763762; -0.645497; -0.000630;,
       -0.928769; 0.310483; 0.202458;,
       -0.058387; 0.996613; -0.057910;,
       0.195973; 0.310458; -0.930167;,
       -0.142061; -0.306070; -0.941350;,
       -0.588965; -0.308463; -0.746975;,
       -0.910888; -0.303732; -0.279340;,
       0.281551; -0.303666; -0.910229;,
       0.746974; -0.308463; -0.588965;,
       0.651352; 0.320800; -0.687625;,
       0.941214; -0.308891; -0.136759;,
       0.921645; 0.317109; -0.223634;,
       -0.008180; 0.998496; -0.054200;,
       0.951033; -0.309010; 0.007042;,
       0.996772; 0.079834; 0.008530;,
       0.240579; 0.970627; 0.002207;,
       -0.854317; 0.519752; -0.001040;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; -0.000000;,
       0.918805; 0.316742; 0.235524;,
       0.574570; -0.813639; 0.088662;,
       0.000000; -1.000000; 0.000000;,
       -0.952403; -0.304738; 0.007939;,
       -0.854467; 0.519461; 0.006796;,
       0.240581; 0.970629; -0.000016;,
       0.996824; 0.079633; -0.000621;,
       0.380847; -0.924638; -0.000635;,
       0.000000; -1.000000; -0.000000;,
       -0.000000; -0.000000; 1.000000;,
       0.391649; 0.127255; 0.911273;,
       -0.000000; 0.411804; 0.911273;,
       -0.391649; 0.127254; 0.911273;,
       -0.242052; -0.333156; 0.911273;,
       0.242052; -0.333156; 0.911273;,
       0.000000; 0.000000; 1.000000;,
       0.000000; 0.411804; 0.911273;,
       -0.391649; 0.127255; 0.911273;,
       -0.242052; -0.333156; 0.911273;,
       0.242052; -0.333156; 0.911273;,
       0.391649; 0.127254; 0.911273;,
       0.997071; 0.076478; 0.000000;,
       0.951056; -0.309018; 0.000000;,
       0.951056; -0.309018; 0.000000;,
       0.851601; 0.524191; 0.000000;,
       0.235377; 0.971904; 0.000000;,
       -0.235377; 0.971904; 0.000000;,
       -0.851600; 0.524191; 0.000000;,
       -0.997071; 0.076479; 0.000000;,
       -0.761695; -0.647935; 0.000000;,
       -0.380848; -0.924638; 0.000000;,
       -0.000000; -1.000000; 0.000000;,
       -0.000000; -1.000000; 0.000000;;
       100;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 0, 3;,
       3;3, 5, 4;,
       3;6, 4, 5;,
       3;5, 7, 6;,
       3;8, 6, 7;,
       3;7, 9, 8;,
       3;10, 8, 9;,
       3;9, 11, 10;,
       3;12, 13, 14;,
       3;15, 12, 16;,
       3;14, 16, 12;,
       3;16, 14, 17;,
       3;18, 17, 14;,
       3;14, 19, 18;,
       3;19, 14, 13;,
       3;13, 20, 19;,
       3;21, 15, 22;,
       3;16, 22, 15;,
       3;22, 16, 23;,
       3;17, 23, 16;,
       3;23, 17, 24;,
       3;25, 24, 17;,
       3;17, 18, 25;,
       3;26, 25, 18;,
       3;18, 27, 26;,
       3;27, 18, 19;,
       3;28, 21, 29;,
       3;22, 29, 21;,
       3;29, 22, 30;,
       3;23, 30, 22;,
       3;30, 23, 31;,
       3;24, 31, 23;,
       3;31, 24, 32;,
       3;33, 32, 24;,
       3;24, 25, 33;,
       3;34, 33, 25;,
       3;32, 35, 31;,
       3;35, 36, 37;,
       3;37, 31, 35;,
       3;31, 37, 30;,
       3;36, 38, 39;,
       3;39, 37, 36;,
       3;37, 39, 40;,
       3;40, 30, 37;,
       3;30, 40, 29;,
       3;38, 41, 42;,
       3;42, 39, 38;,
       3;39, 42, 43;,
       3;43, 40, 39;,
       3;40, 43, 44;,
       3;44, 29, 40;,
       3;29, 44, 28;,
       3;45, 46, 20;,
       3;20, 13, 45;,
       3;47, 45, 13;,
       3;13, 12, 47;,
       3;48, 47, 12;,
       3;12, 15, 48;,
       3;49, 48, 15;,
       3;15, 21, 49;,
       3;50, 49, 21;,
       3;21, 28, 50;,
       3;19, 51, 27;,
       3;51, 19, 20;,
       3;20, 52, 51;,
       3;52, 20, 46;,
       3;46, 53, 52;,
       3;25, 26, 34;,
       3;54, 34, 26;,
       3;26, 55, 54;,
       3;55, 26, 27;,
       3;27, 56, 55;,
       3;56, 27, 51;,
       3;51, 57, 56;,
       3;57, 51, 52;,
       3;52, 58, 57;,
       3;58, 52, 53;,
       3;53, 59, 58;,
       3;60, 61, 62;,
       3;60, 62, 63;,
       3;60, 63, 64;,
       3;60, 64, 65;,
       3;60, 65, 61;,
       3;66, 67, 68;,
       3;66, 68, 69;,
       3;66, 69, 70;,
       3;66, 70, 71;,
       3;66, 71, 67;,
       3;72, 73, 74;,
       3;74, 75, 72;,
       3;76, 72, 75;,
       3;75, 77, 76;,
       3;78, 76, 77;,
       3;77, 79, 78;,
       3;80, 78, 79;,
       3;79, 81, 80;,
       3;82, 80, 81;,
       3;81, 83, 82;;
      }

      MeshTextureCoords {
       84;
       0.696777; 0.468262;,
       0.696777; 0.581055;,
       0.772461; 0.580566;,
       0.772461; 0.467773;,
       0.696777; 0.355469;,
       0.772461; 0.354980;,
       0.696777; 0.242676;,
       0.772461; 0.242310;,
       0.696777; 0.129883;,
       0.772461; 0.129395;,
       0.696777; 0.017075;,
       0.772461; 0.016678;,
       0.318848; 0.916504;,
       0.685547; 0.916504;,
       0.685547; 0.837891;,
       0.291504; 0.916504;,
       0.318848; 0.837891;,
       0.685547; 0.761230;,
       0.712891; 0.761230;,
       0.712891; 0.837891;,
       0.712891; 0.916504;,
       0.264893; 0.916504;,
       0.291504; 0.837891;,
       0.318848; 0.761230;,
       0.685547; 0.685547;,
       0.712891; 0.685547;,
       0.739746; 0.685547;,
       0.739746; 0.761230;,
       0.006634; 0.916504;,
       0.264893; 0.837891;,
       0.291504; 0.761230;,
       0.318848; 0.685547;,
       0.685547; 0.608887;,
       0.712891; 0.608887;,
       0.739746; 0.608887;,
       0.318848; 0.608887;,
       0.291504; 0.608887;,
       0.291504; 0.685547;,
       0.264893; 0.608887;,
       0.264893; 0.685547;,
       0.264893; 0.761230;,
       0.006634; 0.608887;,
       0.006634; 0.685547;,
       0.006634; 0.761230;,
       0.006634; 0.837891;,
       0.685547; 0.991699;,
       0.712891; 0.991699;,
       0.318848; 0.991699;,
       0.291504; 0.991699;,
       0.264893; 0.991699;,
       0.006634; 0.991699;,
       0.739746; 0.837891;,
       0.739746; 0.916504;,
       0.739746; 0.991699;,
       0.998047; 0.608887;,
       0.998047; 0.685547;,
       0.998047; 0.761230;,
       0.998047; 0.837891;,
       0.998047; 0.916504;,
       0.998047; 0.991699;,
       0.515137; 0.246582;,
       0.618164; 0.213135;,
       0.515137; 0.138306;,
       0.412354; 0.213135;,
       0.451660; 0.334229;,
       0.579102; 0.333984;,
       0.516113; 0.486572;,
       0.516113; 0.378174;,
       0.413330; 0.452881;,
       0.452637; 0.573730;,
       0.579590; 0.573730;,
       0.619141; 0.453125;,
       0.697266; 0.470703;,
       0.697266; 0.583496;,
       0.772461; 0.583008;,
       0.772461; 0.470215;,
       0.697266; 0.357910;,
       0.772461; 0.357422;,
       0.697266; 0.245117;,
       0.772461; 0.244751;,
       0.697266; 0.132324;,
       0.772461; 0.131958;,
       0.697266; 0.019501;,
       0.772461; 0.019135;;
      }

      FVFData {
       258;
       168;
       1052221440,
       1054498816,
       1044234240,
       1054498816,
       1040678912,
       1056948224,
       1053999104,
       1056948224,
       1054023680,
       1048961024,
       1056899072,
       1047486464,
       1049313280,
       1042513920,
       1049313280,
       1032740864,
       1040637952,
       1048961024,
       1027375104,
       1047486464,
       1044234240,
       1054498816,
       1040678912,
       1056948224,
       1050886144,
       1063952384,
       1060077568,
       1063952384,
       1060077568,
       1062633472,
       1049968640,
       1063952384,
       1050886144,
       1062633472,
       1060077568,
       1061347328,
       1060536320,
       1061347328,
       1060536320,
       1062633472,
       1060536320,
       1063952384,
       1049075712,
       1063952384,
       1049968640,
       1062633472,
       1050886144,
       1061347328,
       1060077568,
       1060077568,
       1060536320,
       1060077568,
       1060986880,
       1060077568,
       1060986880,
       1061347328,
       1004101632,
       1063952384,
       1049075712,
       1062633472,
       1049968640,
       1061347328,
       1050886144,
       1060077568,
       1060077568,
       1058791424,
       1060536320,
       1058791424,
       1060986880,
       1058791424,
       1050886144,
       1058791424,
       1049968640,
       1058791424,
       1049968640,
       1060077568,
       1049075712,
       1058791424,
       1049075712,
       1060077568,
       1049075712,
       1061347328,
       1004101632,
       1058791424,
       1004101632,
       1060077568,
       1004101632,
       1061347328,
       1004101632,
       1062633472,
       1060077568,
       1065213952,
       1060536320,
       1065213952,
       1050886144,
       1065213952,
       1049968640,
       1065213952,
       1049075712,
       1065213952,
       1004101632,
       1065213952,
       1060986880,
       1062633472,
       1060986880,
       1063952384,
       1060986880,
       1065213952,
       1065320448,
       1058791424,
       1065320448,
       1060077568,
       1065320448,
       1061347328,
       1065320448,
       1062633472,
       1065320448,
       1063952384,
       1065320448,
       1065213952,
       1049313280,
       1050492928,
       1054023680,
       1048961024,
       1049313280,
       1042513920,
       1040637952,
       1048961024,
       1044234240,
       1054498816,
       1052221440,
       1054498816,
       1061289984,
       1050042368,
       1061289984,
       1054998528,
       1063641088,
       1051574272,
       1062748160,
       1043505152,
       1059831808,
       1043505152,
       1058930688,
       1051574272,
       1058930688,
       1051574272,
       1059831808,
       1043505152,
       1058947072,
       1037033472,
       1057497088,
       1052508160,
       1061289984,
       1054998528,
       1061289984,
       1057488896,
       1063641088,
       1051574272,
       1065082880,
       1052508160,
       1062748160,
       1043505152,
       1063632896,
       1037033472,
       1059831808,
       1043505152,
       1058947072,
       1037033472;
      }

      MeshVertexColors {
       84;
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
       83; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       100;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
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

       Material M_LadderBar {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_LadderBar_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "LadderBar";
       84;
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
       83;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {LadderBar}

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