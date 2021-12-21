xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Sun May 14 19:47:32 2017

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

   Frame Lower_Pipe_XL_32 {
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
       86;
       5.847172; 16.395737; -0.000000;,
       5.847172; 11.593543; 11.593537;,
       32.000000; 11.593543; 11.593537;,
       32.000000; 16.395737; -0.000000;,
       5.847172; 11.593545; -11.593537;,
       32.000000; 11.593545; -11.593537;,
       5.847172; -0.000015; -16.395737;,
       32.000000; -0.000015; -16.395737;,
       5.847172; -11.593551; -11.593538;,
       5.847172; -0.000015; -16.395737;,
       32.000000; -0.000015; -16.395737;,
       32.000000; -11.593551; -11.593538;,
       5.847172; -16.395752; -0.000002;,
       32.000000; -16.395752; -0.000002;,
       5.847172; -11.593545; 11.593536;,
       32.000000; -11.593545; 11.593536;,
       5.847172; -0.000001; 16.395741;,
       32.000000; -0.000001; 16.395741;,
       0.000000; 7.382438; 17.822784;,
       0.000000; 13.579085; 13.579085;,
       0.000000; 0.000000; -0.000001;,
       0.000000; 17.822784; 7.382438;,
       0.000000; 19.203728; -0.000000;,
       0.000000; 17.822784; -7.382439;,
       0.000000; 13.579087; -13.579085;,
       0.000000; 7.382440; -17.822784;,
       0.000000; 0.000001; -19.203728;,
       0.000000; -7.382438; -17.822784;,
       0.000000; -13.579085; -13.579087;,
       0.000000; -17.822784; -7.382441;,
       0.000000; -19.203728; -0.000002;,
       0.000000; -17.822784; 7.382437;,
       0.000000; -13.579087; 13.579084;,
       0.000000; -7.382440; 17.822784;,
       0.000000; -0.000001; 19.203728;,
       5.847172; -7.382440; 17.822784;,
       5.847172; -13.579087; 13.579084;,
       5.847172; 0.000000; -0.000001;,
       5.847172; -17.822784; 7.382437;,
       5.847172; -19.203728; -0.000002;,
       5.847172; -17.822784; -7.382441;,
       5.847172; -13.579085; -13.579087;,
       5.847172; -7.382438; -17.822784;,
       5.847172; 0.000001; -19.203728;,
       5.847172; 7.382440; -17.822784;,
       5.847172; 13.579087; -13.579085;,
       5.847172; 17.822784; -7.382439;,
       5.847172; 19.203728; -0.000000;,
       5.847172; 17.822784; 7.382438;,
       5.847172; 13.579085; 13.579085;,
       5.847172; 7.382438; 17.822783;,
       5.847172; -0.000001; 19.203728;,
       5.847172; 13.579085; 13.579085;,
       0.000000; 13.579085; 13.579085;,
       0.000000; 7.382438; 17.822784;,
       5.847172; 7.382438; 17.822783;,
       0.000000; -0.000001; 19.203728;,
       5.847172; -0.000001; 19.203728;,
       0.000000; -7.382440; 17.822784;,
       5.847172; -7.382440; 17.822784;,
       0.000000; -13.579087; 13.579084;,
       5.847172; -13.579087; 13.579084;,
       0.000000; -17.822784; 7.382437;,
       5.847172; -17.822784; 7.382437;,
       0.000000; -19.203728; -0.000002;,
       5.847172; -19.203728; -0.000002;,
       0.000000; -17.822784; -7.382441;,
       5.847172; -17.822784; -7.382441;,
       0.000000; -13.579085; -13.579087;,
       5.847172; -13.579085; -13.579087;,
       0.000000; -7.382438; -17.822784;,
       5.847172; -7.382438; -17.822784;,
       0.000000; 0.000001; -19.203728;,
       5.847172; 0.000001; -19.203728;,
       0.000000; 7.382440; -17.822784;,
       5.847172; 7.382440; -17.822784;,
       0.000000; 13.579087; -13.579085;,
       5.847172; 13.579087; -13.579085;,
       0.000000; 17.822784; -7.382439;,
       5.847172; 17.822784; -7.382439;,
       0.000000; 19.203728; -0.000000;,
       5.847172; 19.203728; -0.000000;,
       0.000000; 17.822784; 7.382438;,
       5.847172; 17.822784; 7.382438;,
       0.000000; 13.579085; 13.579085;,
       5.847172; 13.579085; 13.579085;;
       80;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 0, 3;,
       3;3, 5, 4;,
       3;6, 4, 5;,
       3;5, 7, 6;,
       3;8, 9, 10;,
       3;10, 11, 8;,
       3;12, 8, 11;,
       3;11, 13, 12;,
       3;14, 12, 13;,
       3;13, 15, 14;,
       3;16, 14, 15;,
       3;15, 17, 16;,
       3;1, 16, 17;,
       3;17, 2, 1;,
       3;18, 19, 20;,
       3;20, 19, 21;,
       3;21, 22, 20;,
       3;20, 22, 23;,
       3;23, 24, 20;,
       3;20, 24, 25;,
       3;25, 26, 20;,
       3;20, 26, 27;,
       3;27, 28, 20;,
       3;20, 28, 29;,
       3;29, 30, 20;,
       3;20, 30, 31;,
       3;31, 32, 20;,
       3;20, 32, 33;,
       3;33, 34, 20;,
       3;20, 34, 18;,
       3;35, 36, 37;,
       3;37, 36, 38;,
       3;38, 39, 37;,
       3;37, 39, 40;,
       3;40, 41, 37;,
       3;37, 41, 42;,
       3;42, 43, 37;,
       3;37, 43, 44;,
       3;44, 45, 37;,
       3;37, 45, 46;,
       3;46, 47, 37;,
       3;37, 47, 48;,
       3;48, 49, 37;,
       3;37, 49, 50;,
       3;50, 51, 37;,
       3;37, 51, 35;,
       3;52, 53, 54;,
       3;54, 55, 52;,
       3;55, 54, 56;,
       3;56, 57, 55;,
       3;57, 56, 58;,
       3;58, 59, 57;,
       3;59, 58, 60;,
       3;60, 61, 59;,
       3;61, 60, 62;,
       3;62, 63, 61;,
       3;63, 62, 64;,
       3;64, 65, 63;,
       3;65, 64, 66;,
       3;66, 67, 65;,
       3;67, 66, 68;,
       3;68, 69, 67;,
       3;69, 68, 70;,
       3;70, 71, 69;,
       3;71, 70, 72;,
       3;72, 73, 71;,
       3;73, 72, 74;,
       3;74, 75, 73;,
       3;75, 74, 76;,
       3;76, 77, 75;,
       3;77, 76, 78;,
       3;78, 79, 77;,
       3;79, 78, 80;,
       3;80, 81, 79;,
       3;81, 80, 82;,
       3;82, 83, 81;,
       3;83, 82, 84;,
       3;84, 85, 83;;

      MeshNormals {
       86;
       0.000000; 0.990602; 0.136773;,
       0.000000; 0.603748; 0.797175;,
       0.000000; 0.797175; 0.603748;,
       0.000000; 0.990602; -0.136773;,
       0.000000; 0.797175; -0.603748;,
       0.000000; 0.603748; -0.797175;,
       0.000000; 0.382683; -0.923880;,
       0.000000; 0.382683; -0.923880;,
       0.000000; -0.603748; -0.797175;,
       0.000000; -0.382683; -0.923880;,
       0.000000; -0.382683; -0.923880;,
       0.000000; -0.797175; -0.603748;,
       0.000000; -0.990602; -0.136774;,
       0.000000; -0.990602; 0.136774;,
       0.000000; -0.797175; 0.603748;,
       0.000000; -0.603748; 0.797175;,
       0.000000; -0.136774; 0.990602;,
       0.000000; 0.136774; 0.990602;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       0.000000; 0.565036; 0.825066;,
       0.000000; 0.565036; 0.825066;,
       0.000000; 0.446507; 0.894780;,
       0.000000; 0.316977; 0.948433;,
       0.000000; 0.062232; 0.998062;,
       0.000000; -0.062232; 0.998062;,
       0.000000; -0.316977; 0.948433;,
       0.000000; -0.446507; 0.894780;,
       0.000000; -0.661732; 0.749741;,
       0.000000; -0.749741; 0.661732;,
       0.000000; -0.894780; 0.446507;,
       0.000000; -0.948433; 0.316977;,
       0.000000; -0.998062; 0.062232;,
       0.000000; -0.998062; -0.062232;,
       0.000000; -0.948433; -0.316977;,
       0.000000; -0.894780; -0.446507;,
       0.000000; -0.749741; -0.661732;,
       0.000000; -0.661732; -0.749741;,
       0.000000; -0.446507; -0.894780;,
       0.000000; -0.316977; -0.948433;,
       0.000000; -0.062232; -0.998062;,
       0.000000; 0.062232; -0.998062;,
       0.000000; 0.316977; -0.948433;,
       0.000000; 0.446507; -0.894780;,
       0.000000; 0.661732; -0.749741;,
       0.000000; 0.749741; -0.661732;,
       0.000000; 0.894780; -0.446507;,
       0.000000; 0.948433; -0.316977;,
       0.000000; 0.998062; -0.062232;,
       0.000000; 0.998062; 0.062232;,
       0.000000; 0.948433; 0.316977;,
       0.000000; 0.894780; 0.446507;,
       0.000000; 0.825066; 0.565036;,
       0.000000; 0.825066; 0.565036;;
       80;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 0, 3;,
       3;3, 5, 4;,
       3;6, 4, 5;,
       3;5, 7, 6;,
       3;8, 9, 10;,
       3;10, 11, 8;,
       3;12, 8, 11;,
       3;11, 13, 12;,
       3;14, 12, 13;,
       3;13, 15, 14;,
       3;16, 14, 15;,
       3;15, 17, 16;,
       3;1, 16, 17;,
       3;17, 2, 1;,
       3;18, 19, 20;,
       3;20, 19, 21;,
       3;21, 22, 20;,
       3;20, 22, 23;,
       3;23, 24, 20;,
       3;20, 24, 25;,
       3;25, 26, 20;,
       3;20, 26, 27;,
       3;27, 28, 20;,
       3;20, 28, 29;,
       3;29, 30, 20;,
       3;20, 30, 31;,
       3;31, 32, 20;,
       3;20, 32, 33;,
       3;33, 34, 20;,
       3;20, 34, 18;,
       3;35, 36, 37;,
       3;37, 36, 38;,
       3;38, 39, 37;,
       3;37, 39, 40;,
       3;40, 41, 37;,
       3;37, 41, 42;,
       3;42, 43, 37;,
       3;37, 43, 44;,
       3;44, 45, 37;,
       3;37, 45, 46;,
       3;46, 47, 37;,
       3;37, 47, 48;,
       3;48, 49, 37;,
       3;37, 49, 50;,
       3;50, 51, 37;,
       3;37, 51, 35;,
       3;52, 53, 54;,
       3;54, 55, 52;,
       3;55, 54, 56;,
       3;56, 57, 55;,
       3;57, 56, 58;,
       3;58, 59, 57;,
       3;59, 58, 60;,
       3;60, 61, 59;,
       3;61, 60, 62;,
       3;62, 63, 61;,
       3;63, 62, 64;,
       3;64, 65, 63;,
       3;65, 64, 66;,
       3;66, 67, 65;,
       3;67, 66, 68;,
       3;68, 69, 67;,
       3;69, 68, 70;,
       3;70, 71, 69;,
       3;71, 70, 72;,
       3;72, 73, 71;,
       3;73, 72, 74;,
       3;74, 75, 73;,
       3;75, 74, 76;,
       3;76, 77, 75;,
       3;77, 76, 78;,
       3;78, 79, 77;,
       3;79, 78, 80;,
       3;80, 81, 79;,
       3;81, 80, 82;,
       3;82, 83, 81;,
       3;83, 82, 84;,
       3;84, 85, 83;;
      }

      MeshTextureCoords {
       86;
       0.459717; 0.000031;,
       0.428467; 0.000031;,
       0.428467; 0.202393;,
       0.459717; 0.202393;,
       0.490967; 0.000031;,
       0.490967; 0.202393;,
       0.521973; 0.000031;,
       0.521973; 0.202393;,
       0.303467; 0.000031;,
       0.272217; 0.000031;,
       0.272217; 0.202393;,
       0.303467; 0.202393;,
       0.334717; 0.000031;,
       0.334717; 0.202393;,
       0.365967; 0.000031;,
       0.365967; 0.202393;,
       0.397217; 0.000031;,
       0.397217; 0.202393;,
       0.857910; 0.769043;,
       0.822266; 0.717773;,
       0.709473; 0.830566;,
       0.770996; 0.682129;,
       0.709473; 0.670898;,
       0.647949; 0.682129;,
       0.596191; 0.717773;,
       0.560547; 0.769043;,
       0.549316; 0.830566;,
       0.560547; 0.892090;,
       0.596191; 0.943848;,
       0.647949; 0.979004;,
       0.709473; 0.990723;,
       0.770996; 0.979004;,
       0.822266; 0.943848;,
       0.857910; 0.892090;,
       0.869141; 0.830566;,
       0.539551; 0.545898;,
       0.580566; 0.605957;,
       0.712402; 0.474365;,
       0.640625; 0.647461;,
       0.712402; 0.660645;,
       0.784180; 0.647461;,
       0.844727; 0.605957;,
       0.885742; 0.545898;,
       0.899414; 0.474365;,
       0.885742; 0.402588;,
       0.844727; 0.342285;,
       0.784180; 0.301025;,
       0.712402; 0.287598;,
       0.640625; 0.301025;,
       0.580566; 0.342285;,
       0.539551; 0.402588;,
       0.525879; 0.474365;,
       0.984863; 0.591797;,
       0.888672; 0.591797;,
       0.888672; 0.616211;,
       0.984863; 0.616211;,
       0.888672; 0.640625;,
       0.984863; 0.640625;,
       0.888672; 0.665527;,
       0.984863; 0.665527;,
       0.888672; 0.689941;,
       0.984863; 0.689941;,
       0.888672; 0.714355;,
       0.984863; 0.714355;,
       0.888672; 0.739258;,
       0.984863; 0.739258;,
       0.888672; 0.763672;,
       0.984863; 0.763672;,
       0.888672; 0.788086;,
       0.984863; 0.788086;,
       0.888672; 0.812500;,
       0.984863; 0.812500;,
       0.888672; 0.837402;,
       0.984863; 0.837402;,
       0.888672; 0.861816;,
       0.984863; 0.861816;,
       0.888672; 0.886230;,
       0.984863; 0.886230;,
       0.888672; 0.911133;,
       0.984863; 0.911133;,
       0.888672; 0.935547;,
       0.984863; 0.935547;,
       0.888672; 0.959961;,
       0.984863; 0.959961;,
       0.888672; 0.984863;,
       0.984863; 0.984863;;
      }

      FVFData {
       258;
       172;
       1061093376,
       1003520000,
       1059045376,
       1003520000,
       1059045376,
       1057095680,
       1061093376,
       1057095680,
       1063141376,
       1003520000,
       1063141376,
       1057095680,
       1065181184,
       1003520000,
       1065181184,
       1057095680,
       1040949248,
       1003520000,
       1013784576,
       1003520000,
       1013784576,
       1057095680,
       1040949248,
       1057095680,
       1048854528,
       1003520000,
       1048854528,
       1057095680,
       1052942336,
       1003520000,
       1052942336,
       1057095680,
       1056997376,
       1003520000,
       1056997376,
       1057095680,
       1063796736,
       1060052992,
       1063141376,
       1059102720,
       1061068800,
       1061175296,
       1062199296,
       1058455552,
       1061068800,
       1058250752,
       1059946496,
       1058455552,
       1058996224,
       1059102720,
       1058349056,
       1060052992,
       1058144256,
       1061175296,
       1058349056,
       1062305792,
       1058996224,
       1063247872,
       1059946496,
       1063903232,
       1061068800,
       1064108032,
       1062199296,
       1063903232,
       1063141376,
       1063247872,
       1063796736,
       1062305792,
       1064001536,
       1061175296,
       1043431424,
       1057439744,
       1036771328,
       1058299904,
       1048969216,
       1061019648,
       1027997696,
       1059536896,
       1023713280,
       1061019648,
       1027997696,
       1062502400,
       1036771328,
       1063739392,
       1043431424,
       1064599552,
       1048969216,
       1064861696,
       1051934720,
       1064599552,
       1054408704,
       1063739392,
       1056129024,
       1062502400,
       1056661504,
       1061019648,
       1056129024,
       1059536896,
       1054408704,
       1058299904,
       1051934720,
       1057439744,
       1048969216,
       1057169408,
       1063870464,
       1058381824,
       1063141376,
       1059102720,
       1063796736,
       1060052992,
       1064747008,
       1059659776,
       1064001536,
       1061175296,
       1065025536,
       1061175296,
       1063796736,
       1062305792,
       1064747008,
       1062699008,
       1063141376,
       1063247872,
       1063870464,
       1063976960,
       1062199296,
       1063903232,
       1062592512,
       1064853504,
       1061068800,
       1064108032,
       1061068800,
       1065140224,
       1059946496,
       1063903232,
       1059553280,
       1064853504,
       1058996224,
       1063247872,
       1058275328,
       1063976960,
       1058349056,
       1062305792,
       1057398784,
       1062699008,
       1058144256,
       1061175296,
       1057112064,
       1061175296,
       1058349056,
       1060052992,
       1057398784,
       1059659776,
       1058996224,
       1059102720,
       1058275328,
       1058381824,
       1059946496,
       1058455552,
       1059553280,
       1057505280,
       1061068800,
       1058250752,
       1061068800,
       1057218560,
       1062199296,
       1058455552,
       1062592512,
       1057505280,
       1063141376,
       1059102720,
       1063870464,
       1058381824;
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
       "Lower_Pipe_XL_32";
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
      {Lower_Pipe_XL_32}

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
