xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Thu May 18 12:01:51 2017

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

      Frame Lower_Pipe_XL_256 {
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
       86;
       255.999985; -16.395750; 0.000001;,
       255.999985; -11.593544; -11.593536;,
       5.847168; -11.593544; -11.593536;,
       5.847168; -16.395750; 0.000001;,
       255.999985; -11.593550; 11.593536;,
       5.847168; -11.593550; 11.593536;,
       255.999985; -0.000015; 16.395735;,
       5.847168; -0.000015; 16.395735;,
       255.999985; 11.593544; 11.593535;,
       255.999985; -0.000015; 16.395735;,
       5.847168; -0.000015; 16.395735;,
       5.847168; 11.593544; 11.593535;,
       255.999985; 16.395735; -0.000001;,
       5.847168; 16.395735; -0.000001;,
       255.999985; 11.593542; -11.593537;,
       5.847168; 11.593542; -11.593537;,
       255.999985; -0.000001; -16.395739;,
       5.847168; -0.000001; -16.395739;,
       0.000000; 13.579084; -13.579084;,
       5.847168; 13.579084; -13.579084;,
       5.847168; 17.822783; -7.382438;,
       0.000000; 17.822783; -7.382438;,
       5.847168; 19.203726; -0.000000;,
       0.000000; 19.203726; -0.000000;,
       5.847168; 17.822783; 7.382439;,
       0.000000; 17.822783; 7.382439;,
       5.847168; 13.579086; 13.579084;,
       0.000000; 13.579086; 13.579084;,
       5.847168; 7.382440; 17.822783;,
       0.000000; 7.382440; 17.822783;,
       5.847168; 0.000001; 19.203726;,
       0.000000; 0.000001; 19.203726;,
       5.847168; -7.382438; 17.822783;,
       0.000000; -7.382438; 17.822783;,
       5.847168; -13.579084; 13.579086;,
       0.000000; -13.579084; 13.579086;,
       5.847168; -17.822783; 7.382441;,
       0.000000; -17.822783; 7.382441;,
       5.847168; -19.203726; 0.000002;,
       0.000000; -19.203726; 0.000002;,
       5.847168; -17.822783; -7.382437;,
       0.000000; -17.822783; -7.382437;,
       5.847168; -13.579086; -13.579083;,
       0.000000; -13.579086; -13.579083;,
       5.847168; -7.382440; -17.822783;,
       0.000000; -7.382440; -17.822783;,
       5.847168; -0.000001; -19.203726;,
       0.000000; -0.000001; -19.203726;,
       5.847168; 7.382438; -17.822781;,
       0.000000; 7.382438; -17.822783;,
       5.847168; 13.579084; -13.579084;,
       0.000000; 13.579084; -13.579084;,
       5.847168; 0.000000; 0.000001;,
       5.847168; -13.579084; 13.579086;,
       5.847168; -7.382438; 17.822783;,
       5.847168; 0.000001; 19.203726;,
       5.847168; 7.382440; 17.822783;,
       5.847168; 13.579086; 13.579084;,
       5.847168; 17.822783; 7.382439;,
       5.847168; 19.203726; -0.000000;,
       5.847168; 17.822783; -7.382438;,
       5.847168; 13.579084; -13.579084;,
       5.847168; 7.382438; -17.822781;,
       5.847168; -0.000001; -19.203726;,
       5.847168; -7.382440; -17.822783;,
       5.847168; -13.579086; -13.579083;,
       5.847168; -17.822783; -7.382437;,
       5.847168; -19.203726; 0.000002;,
       5.847168; -17.822783; 7.382441;,
       0.000000; 0.000000; 0.000001;,
       0.000000; -0.000001; -19.203726;,
       0.000000; 7.382438; -17.822783;,
       0.000000; 13.579084; -13.579084;,
       0.000000; 17.822783; -7.382438;,
       0.000000; 19.203726; -0.000000;,
       0.000000; 17.822783; 7.382439;,
       0.000000; 13.579086; 13.579084;,
       0.000000; 7.382440; 17.822783;,
       0.000000; 0.000001; 19.203726;,
       0.000000; -7.382438; 17.822783;,
       0.000000; -13.579084; 13.579086;,
       0.000000; -17.822783; 7.382441;,
       0.000000; -19.203726; 0.000002;,
       0.000000; -17.822783; -7.382437;,
       0.000000; -13.579086; -13.579083;,
       0.000000; -7.382440; -17.822783;;
       80;
       3;2, 1, 0;,
       3;0, 3, 2;,
       3;3, 0, 4;,
       3;4, 5, 3;,
       3;5, 4, 6;,
       3;6, 7, 5;,
       3;10, 9, 8;,
       3;8, 11, 10;,
       3;11, 8, 12;,
       3;12, 13, 11;,
       3;13, 12, 14;,
       3;14, 15, 13;,
       3;15, 14, 16;,
       3;16, 17, 15;,
       3;17, 16, 1;,
       3;1, 2, 17;,
       3;20, 19, 18;,
       3;18, 21, 20;,
       3;22, 20, 21;,
       3;21, 23, 22;,
       3;24, 22, 23;,
       3;23, 25, 24;,
       3;26, 24, 25;,
       3;25, 27, 26;,
       3;28, 26, 27;,
       3;27, 29, 28;,
       3;30, 28, 29;,
       3;29, 31, 30;,
       3;32, 30, 31;,
       3;31, 33, 32;,
       3;34, 32, 33;,
       3;33, 35, 34;,
       3;36, 34, 35;,
       3;35, 37, 36;,
       3;38, 36, 37;,
       3;37, 39, 38;,
       3;40, 38, 39;,
       3;39, 41, 40;,
       3;42, 40, 41;,
       3;41, 43, 42;,
       3;44, 42, 43;,
       3;43, 45, 44;,
       3;46, 44, 45;,
       3;45, 47, 46;,
       3;48, 46, 47;,
       3;47, 49, 48;,
       3;50, 48, 49;,
       3;49, 51, 50;,
       3;54, 53, 52;,
       3;52, 55, 54;,
       3;56, 55, 52;,
       3;52, 57, 56;,
       3;58, 57, 52;,
       3;52, 59, 58;,
       3;60, 59, 52;,
       3;52, 61, 60;,
       3;62, 61, 52;,
       3;52, 63, 62;,
       3;64, 63, 52;,
       3;52, 65, 64;,
       3;66, 65, 52;,
       3;52, 67, 66;,
       3;68, 67, 52;,
       3;52, 53, 68;,
       3;71, 70, 69;,
       3;69, 72, 71;,
       3;73, 72, 69;,
       3;69, 74, 73;,
       3;75, 74, 69;,
       3;69, 76, 75;,
       3;77, 76, 69;,
       3;69, 78, 77;,
       3;79, 78, 69;,
       3;69, 80, 79;,
       3;81, 80, 69;,
       3;69, 82, 81;,
       3;83, 82, 69;,
       3;69, 84, 83;,
       3;85, 84, 69;,
       3;69, 70, 85;;

      MeshNormals {
       86;
       0.000000; -0.990602; -0.136774;,
       0.000000; -0.603748; -0.797175;,
       0.000000; -0.797175; -0.603748;,
       0.000000; -0.990602; 0.136774;,
       0.000000; -0.797175; 0.603748;,
       0.000000; -0.603748; 0.797175;,
       0.000000; -0.382683; 0.923880;,
       0.000000; -0.382683; 0.923880;,
       0.000000; 0.603748; 0.797175;,
       0.000000; 0.382683; 0.923880;,
       0.000000; 0.382683; 0.923880;,
       0.000000; 0.797175; 0.603748;,
       0.000000; 0.990602; 0.136773;,
       0.000000; 0.990602; -0.136773;,
       0.000000; 0.797175; -0.603748;,
       0.000000; 0.603748; -0.797175;,
       0.000000; 0.136774; -0.990602;,
       0.000000; -0.136774; -0.990602;,
       0.000000; 0.825066; -0.565036;,
       0.000000; 0.825066; -0.565036;,
       0.000000; 0.894780; -0.446507;,
       0.000000; 0.948433; -0.316977;,
       0.000000; 0.998062; -0.062232;,
       0.000000; 0.998062; 0.062232;,
       0.000000; 0.948433; 0.316977;,
       0.000000; 0.894780; 0.446507;,
       0.000000; 0.749741; 0.661732;,
       0.000000; 0.661732; 0.749741;,
       0.000000; 0.446507; 0.894780;,
       0.000000; 0.316977; 0.948433;,
       0.000000; 0.062232; 0.998062;,
       0.000000; -0.062232; 0.998062;,
       0.000000; -0.316977; 0.948433;,
       0.000000; -0.446506; 0.894780;,
       0.000000; -0.661732; 0.749741;,
       0.000000; -0.749741; 0.661732;,
       0.000000; -0.894780; 0.446507;,
       0.000000; -0.948433; 0.316977;,
       0.000000; -0.998062; 0.062232;,
       0.000000; -0.998062; -0.062232;,
       0.000000; -0.948433; -0.316977;,
       0.000000; -0.894780; -0.446506;,
       0.000000; -0.749741; -0.661732;,
       0.000000; -0.661732; -0.749741;,
       0.000000; -0.446507; -0.894780;,
       0.000000; -0.316977; -0.948433;,
       0.000000; -0.062232; -0.998062;,
       0.000000; 0.062232; -0.998062;,
       0.000000; 0.316977; -0.948433;,
       0.000000; 0.446507; -0.894780;,
       0.000000; 0.565036; -0.825066;,
       0.000000; 0.565036; -0.825066;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
       1.000000; 0.000000; -0.000000;,
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
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;,
       -1.000000; 0.000000; -0.000000;;
       80;
       3;2, 1, 0;,
       3;0, 3, 2;,
       3;3, 0, 4;,
       3;4, 5, 3;,
       3;5, 4, 6;,
       3;6, 7, 5;,
       3;10, 9, 8;,
       3;8, 11, 10;,
       3;11, 8, 12;,
       3;12, 13, 11;,
       3;13, 12, 14;,
       3;14, 15, 13;,
       3;15, 14, 16;,
       3;16, 17, 15;,
       3;17, 16, 1;,
       3;1, 2, 17;,
       3;20, 19, 18;,
       3;18, 21, 20;,
       3;22, 20, 21;,
       3;21, 23, 22;,
       3;24, 22, 23;,
       3;23, 25, 24;,
       3;26, 24, 25;,
       3;25, 27, 26;,
       3;28, 26, 27;,
       3;27, 29, 28;,
       3;30, 28, 29;,
       3;29, 31, 30;,
       3;32, 30, 31;,
       3;31, 33, 32;,
       3;34, 32, 33;,
       3;33, 35, 34;,
       3;36, 34, 35;,
       3;35, 37, 36;,
       3;38, 36, 37;,
       3;37, 39, 38;,
       3;40, 38, 39;,
       3;39, 41, 40;,
       3;42, 40, 41;,
       3;41, 43, 42;,
       3;44, 42, 43;,
       3;43, 45, 44;,
       3;46, 44, 45;,
       3;45, 47, 46;,
       3;48, 46, 47;,
       3;47, 49, 48;,
       3;50, 48, 49;,
       3;49, 51, 50;,
       3;54, 53, 52;,
       3;52, 55, 54;,
       3;56, 55, 52;,
       3;52, 57, 56;,
       3;58, 57, 52;,
       3;52, 59, 58;,
       3;60, 59, 52;,
       3;52, 61, 60;,
       3;62, 61, 52;,
       3;52, 63, 62;,
       3;64, 63, 52;,
       3;52, 65, 64;,
       3;66, 65, 52;,
       3;52, 67, 66;,
       3;68, 67, 52;,
       3;52, 53, 68;,
       3;71, 70, 69;,
       3;69, 72, 71;,
       3;73, 72, 69;,
       3;69, 74, 73;,
       3;75, 74, 69;,
       3;69, 76, 75;,
       3;77, 76, 69;,
       3;69, 78, 77;,
       3;79, 78, 69;,
       3;69, 80, 79;,
       3;81, 80, 69;,
       3;69, 82, 81;,
       3;83, 82, 69;,
       3;69, 84, 83;,
       3;85, 84, 69;,
       3;69, 70, 85;;
      }

      MeshTextureCoords {
       86;
       0.076172; 1.000000;,
       0.107422; 1.000000;,
       0.107422; 0.000031;,
       0.076172; 0.000031;,
       0.044952; 1.000000;,
       0.044952; 0.000031;,
       0.013710; 1.000000;,
       0.013710; 0.000031;,
       0.232422; 1.000000;,
       0.263672; 1.000000;,
       0.263672; 0.000031;,
       0.232422; 0.000031;,
       0.201172; 1.000000;,
       0.201172; 0.000031;,
       0.169922; 1.000000;,
       0.169922; 0.000031;,
       0.138672; 1.000000;,
       0.138672; 0.000031;,
       0.888672; 0.984863;,
       0.984863; 0.984863;,
       0.984863; 0.959961;,
       0.888672; 0.959961;,
       0.984863; 0.935547;,
       0.888672; 0.935547;,
       0.984863; 0.911133;,
       0.888672; 0.911133;,
       0.984863; 0.886230;,
       0.888672; 0.886230;,
       0.984863; 0.861816;,
       0.888672; 0.861816;,
       0.984863; 0.837402;,
       0.888672; 0.837402;,
       0.984863; 0.812500;,
       0.888672; 0.812500;,
       0.984863; 0.788086;,
       0.888672; 0.788086;,
       0.984863; 0.763672;,
       0.888672; 0.763672;,
       0.984863; 0.739258;,
       0.888672; 0.739258;,
       0.984863; 0.714355;,
       0.888672; 0.714355;,
       0.984863; 0.689941;,
       0.888672; 0.689941;,
       0.984863; 0.665527;,
       0.888672; 0.665527;,
       0.984863; 0.640625;,
       0.888672; 0.640625;,
       0.984863; 0.616211;,
       0.888672; 0.616211;,
       0.984863; 0.591797;,
       0.888672; 0.591797;,
       0.714355; 0.471680;,
       0.845215; 0.602051;,
       0.885742; 0.542480;,
       0.899414; 0.471680;,
       0.885742; 0.400635;,
       0.845215; 0.341064;,
       0.785645; 0.300049;,
       0.714355; 0.286865;,
       0.643555; 0.300049;,
       0.583984; 0.341064;,
       0.542969; 0.400635;,
       0.529785; 0.471680;,
       0.542969; 0.542480;,
       0.583984; 0.602051;,
       0.643555; 0.643066;,
       0.714355; 0.656250;,
       0.785645; 0.643066;,
       0.710449; 0.833008;,
       0.869629; 0.833008;,
       0.858398; 0.771973;,
       0.823242; 0.720703;,
       0.771973; 0.685547;,
       0.710449; 0.674316;,
       0.649414; 0.685547;,
       0.598145; 0.720703;,
       0.562988; 0.771973;,
       0.551758; 0.833008;,
       0.562988; 0.894043;,
       0.598145; 0.945313;,
       0.649414; 0.980469;,
       0.710449; 0.992188;,
       0.771973; 0.980469;,
       0.823242; 0.945313;,
       0.858398; 0.894043;;
      }

      FVFData {
       258;
       172;
       1040146432,
       1065132032,
       1043890176,
       1065132032,
       1043890176,
       1006026752,
       1040146432,
       1006026752,
       1032691712,
       1065132032,
       1032691712,
       1006026752,
       1012965376,
       1065132032,
       1012965376,
       1006026752,
       1053679616,
       1065132032,
       1055539200,
       1065132032,
       1055539200,
       1006026752,
       1053679616,
       1006026752,
       1051820032,
       1065132032,
       1051820032,
       1006026752,
       1049952256,
       1065132032,
       1049952256,
       1006026752,
       1047609344,
       1065132032,
       1047609344,
       1006026752,
       1063616512,
       1036771328,
       1064198144,
       1032118272,
       1063174144,
       1019027456,
       1062854656,
       1032617984,
       1061953536,
       1008435200,
       1061953536,
       1030733824,
       1060732928,
       1019027456,
       1061052416,
       1032617984,
       1059708928,
       1032118272,
       1060290560,
       1036771328,
       1059004416,
       1040244736,
       1059774464,
       1041514496,
       1058775040,
       1045127168,
       1059602432,
       1045127168,
       1059004416,
       1049288704,
       1059774464,
       1048657920,
       1059708928,
       1051336704,
       1060290560,
       1050173440,
       1060732928,
       1052737536,
       1061052416,
       1051213824,
       1061953536,
       1053196288,
       1061953536,
       1051549696,
       1063174144,
       1052737536,
       1062854656,
       1051213824,
       1064198144,
       1051336704,
       1063616512,
       1050173440,
       1064894464,
       1049288704,
       1064132608,
       1048657920,
       1065123840,
       1045127168,
       1064304640,
       1045127168,
       1064894464,
       1040244736,
       1064132608,
       1041514496,
       1064198144,
       1032118272,
       1063616512,
       1036771328,
       1061879808,
       1058340864,
       1059725312,
       1060503552,
       1060708352,
       1061183488,
       1061879808,
       1061396480,
       1063059456,
       1061183488,
       1064042496,
       1060503552,
       1064722432,
       1059520512,
       1064935424,
       1058340864,
       1064722432,
       1057169408,
       1064042496,
       1055408128,
       1063059456,
       1054040064,
       1061879808,
       1053614080,
       1060708352,
       1054040064,
       1059725312,
       1055408128,
       1059037184,
       1057169408,
       1058832384,
       1058340864,
       1059037184,
       1059520512,
       1061953536,
       1045127168,
       1064304640,
       1045127168,
       1064132608,
       1041514496,
       1063616512,
       1036771328,
       1062854656,
       1032617984,
       1061953536,
       1030733824,
       1061052416,
       1032617984,
       1060290560,
       1036771328,
       1059774464,
       1041514496,
       1059602432,
       1045127168,
       1059774464,
       1048657920,
       1060290560,
       1050173440,
       1061052416,
       1051213824,
       1061953536,
       1051549696,
       1062854656,
       1051213824,
       1063616512,
       1050173440,
       1064132608,
       1048657920;
      }

      MeshVertexColors {
       86;
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
       85; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       80;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
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

       Material M_Lower_Pipes_XL_INST {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_Lower_Pipes_XL_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "Lower_Pipe_XL_256";
       86;
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
       85;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {Lower_Pipe_XL_256}

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