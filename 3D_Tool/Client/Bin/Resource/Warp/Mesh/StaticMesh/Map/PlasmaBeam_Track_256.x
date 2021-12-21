xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Sun May 14 21:01:24 2017

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

   Frame PlasmaBeam_Track_256 {
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
       28;
       0.000000; -6.822946; -2.606499;,
       -255.999985; -6.822946; -2.606499;,
       0.000000; -3.281142; -2.606499;,
       -255.999985; -3.281142; -2.606499;,
       -255.999985; 8.217915; 0.000000;,
       0.000000; 8.217915; 0.000000;,
       -255.999985; 6.822937; -2.606499;,
       0.000000; 6.822937; -2.606499;,
       0.000000; 2.571461; -1.166597;,
       -255.999985; 2.571461; -1.166597;,
       0.000000; 3.281143; -2.606499;,
       -255.999985; 3.281143; -2.606499;,
       -255.999985; -2.571462; -1.166597;,
       0.000000; -2.571462; -1.166597;,
       -255.999985; -3.281142; -2.606499;,
       0.000000; -3.281142; -2.606499;,
       0.000000; -8.217915; -0.000000;,
       -255.999985; -8.217915; -0.000000;,
       0.000000; -6.822946; -2.606499;,
       -255.999985; -6.822946; -2.606499;,
       0.000000; 3.281143; -2.606499;,
       -255.999985; 3.281143; -2.606499;,
       0.000000; 6.822937; -2.606499;,
       -255.999985; 6.822937; -2.606499;,
       0.000000; 2.571461; -1.166597;,
       0.000000; -2.571462; -1.166597;,
       -255.999985; 2.571461; -1.166597;,
       -255.999985; -2.571462; -1.166597;;
       14;
       3;0, 1, 2;,
       3;2, 1, 3;,
       3;4, 5, 6;,
       3;6, 5, 7;,
       3;8, 9, 10;,
       3;10, 9, 11;,
       3;12, 13, 14;,
       3;14, 13, 15;,
       3;16, 17, 18;,
       3;18, 17, 19;,
       3;20, 21, 22;,
       3;22, 21, 23;,
       3;24, 25, 26;,
       3;26, 25, 27;;

      MeshNormals {
       28;
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.881672; -0.471864;,
       0.000000; 0.881672; -0.471864;,
       0.000000; 0.881672; -0.471864;,
       0.000000; 0.881672; -0.471864;,
       0.000000; -0.896971; -0.442089;,
       0.000000; -0.896971; -0.442089;,
       0.000000; -0.896971; -0.442089;,
       0.000000; -0.896971; -0.442089;,
       0.000000; 0.896972; -0.442088;,
       0.000000; 0.896972; -0.442088;,
       0.000000; 0.896972; -0.442088;,
       0.000000; 0.896972; -0.442088;,
       0.000000; -0.881673; -0.471861;,
       0.000000; -0.881673; -0.471861;,
       0.000000; -0.881673; -0.471861;,
       0.000000; -0.881673; -0.471861;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;;
       14;
       3;0, 1, 2;,
       3;2, 1, 3;,
       3;4, 5, 6;,
       3;6, 5, 7;,
       3;8, 9, 10;,
       3;10, 9, 11;,
       3;12, 13, 14;,
       3;14, 13, 15;,
       3;16, 17, 18;,
       3;18, 17, 19;,
       3;20, 21, 22;,
       3;22, 21, 23;,
       3;24, 25, 26;,
       3;26, 25, 27;;
      }

      MeshTextureCoords {
       28;
       1.000000; 0.910156;,
       0.000031; 0.910156;,
       1.000000; 0.696777;,
       0.000031; 0.696777;,
       0.000031; 0.000031;,
       1.000000; 0.000031;,
       0.000031; 0.087402;,
       1.000000; 0.087402;,
       1.000000; 0.339600;,
       0.000031; 0.339600;,
       1.000000; 0.282227;,
       0.000031; 0.282227;,
       0.000031; 0.653809;,
       1.000000; 0.653809;,
       0.000031; 0.696777;,
       1.000000; 0.696777;,
       1.000000; 1.000000;,
       0.000031; 1.000000;,
       1.000000; 0.910156;,
       0.000031; 0.910156;,
       1.000000; 0.282227;,
       0.000031; 0.282227;,
       1.000000; 0.087402;,
       0.000031; 0.087402;,
       1.000000; 0.339600;,
       1.000000; 0.653809;,
       0.000031; 0.339600;,
       0.000031; 0.653809;;
      }

      FVFData {
       258;
       56;
       939524096,
       1063895040,
       1065353216,
       1063895040,
       939524096,
       1060298752,
       1065353216,
       1060298752,
       1065353216,
       939524096,
       939524096,
       939524096,
       1065353216,
       1035067392,
       939524096,
       1035067392,
       939524096,
       1051738112,
       1065353216,
       1051738112,
       939524096,
       1050296320,
       1065353216,
       1050296320,
       1065353216,
       1059577856,
       939524096,
       1059577856,
       1065353216,
       1060298752,
       939524096,
       1060298752,
       939524096,
       1065353216,
       1065353216,
       1065353216,
       939524096,
       1063895040,
       1065353216,
       1063895040,
       939524096,
       1050296320,
       1065353216,
       1050296320,
       939524096,
       1035067392,
       1065353216,
       1035067392,
       939524096,
       1051738112,
       939524096,
       1059577856,
       1065353216,
       1051738112,
       1065353216,
       1059577856;
      }

      MeshVertexColors {
       28;
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
       27; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       14;
       0,
       0,
       0,
       0,
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
       "PlasmaBeam_Track_256";
       28;
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
       27;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {PlasmaBeam_Track_256}

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