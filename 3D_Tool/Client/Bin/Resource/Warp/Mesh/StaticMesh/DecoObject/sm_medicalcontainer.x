xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Mon May 15 18:31:34 2017

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

   Frame sm_medicalcontainer {
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
       104;
       15.790510; 7.518606; 2.085675;,
       15.036533; 7.518606; -3.005745;,
       12.823186; 1.450151; 1.450756;,
       12.214791; 1.450151; -2.297327;,
       10.139949; 0.736541; 5.119058;,
       4.948615; 0.736541; 3.598202;,
       13.666472; 0.736541; 1.732419;,
       12.929955; 0.736541; -2.804972;,
       7.444628; 0.736541; -5.781197;,
       0.777218; 0.736541; -6.551185;,
       -3.570769; 0.736541; 3.523815;,
       -5.902621; 0.736541; -5.897739;,
       -12.254717; 0.736541; 1.506087;,
       -11.439082; 0.736541; -3.017751;,
       -8.787868; 0.736541; 4.953789;,
       -7.522955; 7.518606; -7.879238;,
       -11.439082; 0.736541; -3.017751;,
       -14.420794; 7.518606; -3.961110;,
       -5.902621; 0.736541; -5.897739;,
       0.796623; 7.518607; -8.773591;,
       0.777218; 0.736541; -6.551185;,
       7.444628; 0.736541; -5.781197;,
       9.099315; 7.518606; -7.734101;,
       12.929955; 0.736541; -2.804972;,
       15.927685; 7.518606; -3.696122;,
       -3.673331; 1.450151; 2.735627;,
       -11.406641; 1.450151; 1.239193;,
       -8.556121; 1.450151; 4.073970;,
       9.923600; 1.450151; 4.235326;,
       12.823186; 1.450151; 1.450756;,
       5.064924; 1.450151; 2.811925;,
       7.203032; 1.450151; -5.016604;,
       0.770305; 1.450151; -5.759489;,
       -5.674413; 1.450151; -5.129043;,
       -10.732891; 1.450151; -2.497695;,
       12.214791; 1.450151; -2.297327;,
       -14.384600; 7.518606; 1.822200;,
       -11.406641; 1.450151; 1.239193;,
       -13.541833; 7.518606; -3.255278;,
       -10.732891; 1.450151; -2.497695;,
       -11.439082; 0.736541; -3.017751;,
       -12.254717; 0.736541; 1.506087;,
       -14.420794; 7.518606; -3.961110;,
       -15.441040; 7.518606; 2.185632;,
       12.929955; 0.736541; -2.804972;,
       15.927685; 7.518606; -3.696122;,
       13.666472; 0.736541; 1.732419;,
       16.840443; 7.518606; 2.467499;,
       12.445238; 7.518606; 7.071960;,
       10.139949; 0.736541; 5.119058;,
       5.981562; 7.518606; 5.010907;,
       10.139949; 0.736541; 5.119058;,
       12.445238; 7.518606; 7.071960;,
       4.948615; 0.736541; 3.598202;,
       -4.628227; 7.518606; 4.918266;,
       -3.570769; 0.736541; 3.523815;,
       -8.787868; 0.736541; 4.953789;,
       -11.126906; 7.518606; 6.866139;,
       -12.254717; 0.736541; 1.506087;,
       -15.441040; 7.518606; 2.185632;,
       15.036533; 7.518606; -3.005745;,
       8.797681; 7.518606; -6.695110;,
       12.214791; 1.450151; -2.297327;,
       7.203032; 1.450151; -5.016604;,
       0.787231; 7.518606; -7.698012;,
       0.770305; 1.450151; -5.759489;,
       -5.674413; 1.450151; -5.129043;,
       -7.239509; 7.518606; -6.835140;,
       -10.732891; 1.450151; -2.497695;,
       -13.541833; 7.518606; -3.255278;,
       15.790510; 7.518606; 2.085675;,
       12.823186; 1.450151; 1.450756;,
       12.176675; 7.518606; 5.871566;,
       9.923600; 1.450151; 4.235326;,
       6.127188; 7.518606; 3.942583;,
       5.064924; 1.450151; 2.811925;,
       -3.673331; 1.450151; 2.735627;,
       -4.755176; 7.518606; 3.847563;,
       -8.556121; 1.450151; 4.073970;,
       -10.837424; 7.518606; 5.670617;,
       -11.406641; 1.450151; 1.239193;,
       -14.384600; 7.518606; 1.822200;,
       16.840443; 7.518606; 2.467499;,
       12.176675; 7.518606; 5.871566;,
       12.445238; 7.518606; 7.071960;,
       5.981562; 7.518606; 5.010907;,
       6.127188; 7.518606; 3.942583;,
       -4.628227; 7.518606; 4.918266;,
       -4.755176; 7.518606; 3.847563;,
       -10.837424; 7.518606; 5.670617;,
       -11.126906; 7.518606; 6.866139;,
       -15.441040; 7.518606; 2.185632;,
       -14.384600; 7.518606; 1.822200;,
       -13.541833; 7.518606; -3.255278;,
       -14.420794; 7.518606; -3.961110;,
       -7.522955; 7.518606; -7.879238;,
       -7.239509; 7.518606; -6.835140;,
       0.796623; 7.518607; -8.773591;,
       0.787231; 7.518606; -7.698012;,
       8.797681; 7.518606; -6.695110;,
       9.099315; 7.518606; -7.734101;,
       15.036533; 7.518606; -3.005745;,
       15.927685; 7.518606; -3.696122;,
       15.790510; 7.518606; 2.085675;;
       84;
       3;0, 1, 2;,
       3;2, 1, 3;,
       3;4, 5, 6;,
       3;7, 6, 8;,
       3;8, 6, 5;,
       3;5, 9, 8;,
       3;10, 9, 5;,
       3;11, 9, 10;,
       3;10, 12, 11;,
       3;11, 12, 13;,
       3;14, 12, 10;,
       3;15, 16, 17;,
       3;18, 16, 15;,
       3;15, 19, 18;,
       3;18, 19, 20;,
       3;20, 19, 21;,
       3;21, 19, 22;,
       3;22, 23, 21;,
       3;24, 23, 22;,
       3;25, 26, 27;,
       3;28, 29, 30;,
       3;31, 30, 29;,
       3;31, 32, 30;,
       3;25, 30, 32;,
       3;33, 25, 32;,
       3;33, 26, 25;,
       3;34, 26, 33;,
       3;29, 35, 31;,
       3;36, 37, 38;,
       3;38, 37, 39;,
       3;40, 41, 42;,
       3;42, 41, 43;,
       3;44, 45, 46;,
       3;46, 45, 47;,
       3;48, 46, 47;,
       3;49, 46, 48;,
       3;50, 51, 52;,
       3;53, 51, 50;,
       3;50, 54, 53;,
       3;53, 54, 55;,
       3;55, 54, 56;,
       3;56, 54, 57;,
       3;56, 57, 58;,
       3;58, 57, 59;,
       3;60, 61, 62;,
       3;62, 61, 63;,
       3;61, 64, 63;,
       3;63, 64, 65;,
       3;64, 66, 65;,
       3;67, 66, 64;,
       3;67, 68, 66;,
       3;69, 68, 67;,
       3;70, 71, 72;,
       3;72, 71, 73;,
       3;72, 73, 74;,
       3;74, 73, 75;,
       3;76, 74, 75;,
       3;77, 74, 76;,
       3;78, 77, 76;,
       3;79, 77, 78;,
       3;80, 79, 78;,
       3;81, 79, 80;,
       3;82, 83, 84;,
       3;84, 83, 85;,
       3;85, 83, 86;,
       3;85, 86, 87;,
       3;87, 86, 88;,
       3;88, 89, 87;,
       3;87, 89, 90;,
       3;90, 89, 91;,
       3;91, 89, 92;,
       3;92, 93, 91;,
       3;91, 93, 94;,
       3;94, 93, 95;,
       3;95, 93, 96;,
       3;95, 96, 97;,
       3;97, 96, 98;,
       3;98, 99, 97;,
       3;97, 99, 100;,
       3;99, 101, 100;,
       3;100, 101, 102;,
       3;102, 101, 82;,
       3;82, 101, 103;,
       3;103, 83, 82;;

      MeshNormals {
       104;
       -0.895821; 0.424154; 0.132660;,
       -0.893274; 0.427604; 0.138622;,
       -0.893274; 0.427604; 0.138622;,
       -0.890680; 0.431030; 0.144577;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       -0.339489; -0.327805; -0.881641;,
       -0.450498; -0.333501; -0.828148;,
       -0.467887; -0.320280; -0.823712;,
       -0.212154; -0.323866; -0.922009;,
       0.008309; -0.307301; -0.951576;,
       0.008297; -0.311407; -0.950240;,
       0.228222; -0.323866; -0.918164;,
       0.354833; -0.327805; -0.875579;,
       0.464890; -0.333501; -0.820155;,
       0.482199; -0.320280; -0.815417;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.893367; 0.424154; 0.148282;,
       0.890717; 0.427604; 0.154199;,
       0.890717; 0.427604; 0.154199;,
       0.888019; 0.431031; 0.160107;,
       -0.894973; -0.415916; -0.161361;,
       -0.897812; -0.412039; -0.155426;,
       -0.897812; -0.412039; -0.155426;,
       -0.900599; -0.408138; -0.149483;,
       0.897654; -0.415917; -0.145709;,
       0.900389; -0.412039; -0.139726;,
       0.852064; -0.442500; 0.279608;,
       0.858823; -0.431799; 0.275630;,
       0.651061; -0.393684; 0.648948;,
       0.633267; -0.405135; 0.659423;,
       -0.197046; -0.177110; 0.964264;,
       -0.288619; -0.161917; 0.943654;,
       -0.299446; -0.168628; 0.939094;,
       -0.099117; -0.188428; 0.977072;,
       0.133128; -0.184176; 0.973836;,
       0.127508; -0.180639; 0.975249;,
       -0.037948; -0.275131; 0.960658;,
       -0.395792; -0.363315; 0.843416;,
       -0.662293; -0.393684; 0.637480;,
       -0.679532; -0.382013; 0.626341;,
       -0.482334; 0.319495; 0.815645;,
       -0.355068; 0.324657; 0.876655;,
       -0.465031; 0.332688; 0.820405;,
       -0.228488; 0.318598; 0.919939;,
       -0.008329; 0.299845; 0.953952;,
       -0.008317; 0.304304; 0.952539;,
       0.212389; 0.318598; 0.923789;,
       0.339706; 0.324657; 0.882722;,
       0.450634; 0.332688; 0.828400;,
       0.468018; 0.319495; 0.823943;,
       -0.665498; 0.391876; -0.635253;,
       -0.648545; 0.401846; -0.646459;,
       -0.379606; 0.360566; -0.851993;,
       -0.019588; 0.258391; -0.965842;,
       0.150738; 0.160306; -0.975490;,
       0.145100; 0.156622; -0.976942;,
       -0.082366; 0.165394; -0.982782;,
       -0.180925; 0.152359; -0.971624;,
       0.036450; 0.258391; -0.965353;,
       0.394426; 0.360566; -0.845234;,
       0.659734; 0.401846; -0.635036;,
       0.676489; 0.391876; -0.623535;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       -0.000000; 1.000000; 0.000000;,
       -0.000000; 1.000000; 0.000000;,
       -0.000000; 1.000000; 0.000000;,
       -0.000000; 1.000000; 0.000001;,
       -0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;;
       84;
       3;0, 1, 2;,
       3;2, 1, 3;,
       3;4, 5, 6;,
       3;7, 6, 8;,
       3;8, 6, 5;,
       3;5, 9, 8;,
       3;10, 9, 5;,
       3;11, 9, 10;,
       3;10, 12, 11;,
       3;11, 12, 13;,
       3;14, 12, 10;,
       3;15, 16, 17;,
       3;18, 16, 15;,
       3;15, 19, 18;,
       3;18, 19, 20;,
       3;20, 19, 21;,
       3;21, 19, 22;,
       3;22, 23, 21;,
       3;24, 23, 22;,
       3;25, 26, 27;,
       3;28, 29, 30;,
       3;31, 30, 29;,
       3;31, 32, 30;,
       3;25, 30, 32;,
       3;33, 25, 32;,
       3;33, 26, 25;,
       3;34, 26, 33;,
       3;29, 35, 31;,
       3;36, 37, 38;,
       3;38, 37, 39;,
       3;40, 41, 42;,
       3;42, 41, 43;,
       3;44, 45, 46;,
       3;46, 45, 47;,
       3;48, 46, 47;,
       3;49, 46, 48;,
       3;50, 51, 52;,
       3;53, 51, 50;,
       3;50, 54, 53;,
       3;53, 54, 55;,
       3;55, 54, 56;,
       3;56, 54, 57;,
       3;56, 57, 58;,
       3;58, 57, 59;,
       3;60, 61, 62;,
       3;62, 61, 63;,
       3;61, 64, 63;,
       3;63, 64, 65;,
       3;64, 66, 65;,
       3;67, 66, 64;,
       3;67, 68, 66;,
       3;69, 68, 67;,
       3;70, 71, 72;,
       3;72, 71, 73;,
       3;72, 73, 74;,
       3;74, 73, 75;,
       3;76, 74, 75;,
       3;77, 74, 76;,
       3;78, 77, 76;,
       3;79, 77, 78;,
       3;80, 79, 78;,
       3;81, 79, 80;,
       3;82, 83, 84;,
       3;84, 83, 85;,
       3;85, 83, 86;,
       3;85, 86, 87;,
       3;87, 86, 88;,
       3;88, 89, 87;,
       3;87, 89, 90;,
       3;90, 89, 91;,
       3;91, 89, 92;,
       3;92, 93, 91;,
       3;91, 93, 94;,
       3;94, 93, 95;,
       3;95, 93, 96;,
       3;95, 96, 97;,
       3;97, 96, 98;,
       3;98, 99, 97;,
       3;97, 99, 100;,
       3;99, 101, 100;,
       3;100, 101, 102;,
       3;102, 101, 82;,
       3;82, 101, 103;,
       3;103, 83, 82;;
      }

      MeshTextureCoords {
       104;
       0.233276; 0.961426;,
       0.314453; 0.989258;,
       0.286621; 0.861328;,
       0.346680; 0.881836;,
       0.232056; 0.405029;,
       0.311523; 0.412109;,
       0.203735; 0.351563;,
       0.216064; 0.297119;,
       0.287598; 0.260986;,
       0.386963; 0.251709;,
       0.455322; 0.417725;,
       0.485840; 0.266357;,
       0.564941; 0.360107;,
       0.555176; 0.305664;,
       0.534668; 0.412598;,
       0.557617; 0.159668;,
       0.555176; 0.305664;,
       0.649414; 0.276611;,
       0.485840; 0.266357;,
       0.390869; 0.108582;,
       0.386963; 0.251709;,
       0.287598; 0.260986;,
       0.221191; 0.150146;,
       0.216064; 0.297119;,
       0.122192; 0.262939;,
       0.505371; 0.642578;,
       0.683594; 0.666992;,
       0.614746; 0.605957;,
       0.193604; 0.625488;,
       0.130981; 0.692383;,
       0.306152; 0.651855;,
       0.267090; 0.833008;,
       0.414551; 0.841797;,
       0.560547; 0.819336;,
       0.672852; 0.753418;,
       0.149536; 0.777344;,
       0.878906; 0.836914;,
       0.791992; 0.763672;,
       0.813965; 0.893066;,
       0.744141; 0.805176;,
       0.555176; 0.305664;,
       0.564941; 0.360107;,
       0.649414; 0.276611;,
       0.658691; 0.373291;,
       0.216064; 0.297119;,
       0.122192; 0.262939;,
       0.203735; 0.351563;,
       0.108032; 0.360596;,
       0.150513; 0.450439;,
       0.232056; 0.405029;,
       0.249756; 0.564453;,
       0.232056; 0.405029;,
       0.150513; 0.450439;,
       0.311523; 0.412109;,
       0.512695; 0.566406;,
       0.455322; 0.417725;,
       0.534668; 0.412598;,
       0.613281; 0.459473;,
       0.564941; 0.360107;,
       0.658691; 0.373291;,
       0.314453; 0.989258;,
       0.435791; 0.986816;,
       0.346680; 0.881836;,
       0.441895; 0.878418;,
       0.568848; 0.965820;,
       0.548828; 0.861328;,
       0.654297; 0.837402;,
       0.700195; 0.935547;,
       0.744141; 0.805176;,
       0.813965; 0.893066;,
       0.967773; 0.283203;,
       0.862305; 0.325439;,
       0.980469; 0.369629;,
       0.871094; 0.392090;,
       0.958984; 0.473633;,
       0.854004; 0.474854;,
       0.831055; 0.619141;,
       0.930176; 0.653320;,
       0.821289; 0.703125;,
       0.917969; 0.758789;,
       0.791992; 0.763672;,
       0.878906; 0.836914;,
       0.108032; 0.360596;,
       0.128540; 0.461914;,
       0.150513; 0.450439;,
       0.249756; 0.564453;,
       0.237915; 0.591797;,
       0.512695; 0.566406;,
       0.522949; 0.591797;,
       0.634277; 0.471436;,
       0.613281; 0.459473;,
       0.658691; 0.373291;,
       0.676270; 0.375488;,
       0.672363; 0.270996;,
       0.649414; 0.276611;,
       0.557617; 0.159668;,
       0.572754; 0.141846;,
       0.390869; 0.108582;,
       0.391602; 0.084167;,
       0.206787; 0.131348;,
       0.221191; 0.150146;,
       0.099304; 0.256104;,
       0.122192; 0.262939;,
       0.090088; 0.361816;;
      }

      FVFData {
       258;
       208;
       1050206208,
       1049812992,
       1045536768,
       1049812992,
       1049812992,
       1053564928,
       1046413312,
       1053564928,
       1064681472,
       1054105600,
       1064214528,
       1050894336,
       1063632896,
       1056284672,
       1062232064,
       1055834112,
       1061306368,
       1052442624,
       1061068800,
       1048051712,
       1064189952,
       1042677760,
       1061273600,
       1039392768,
       1063567360,
       990019584,
       1062166528,
       1015775232,
       1064632320,
       1032257536,
       1050255360,
       1058062336,
       1054457856,
       1056735232,
       1050255360,
       1054892032,
       1054457856,
       1058562048,
       1050255360,
       1060634624,
       1054457856,
       1060626432,
       1054457856,
       1062690816,
       1050255360,
       1063206912,
       1054457856,
       1064386560,
       1050255360,
       1065312256,
       1058340864,
       1042735104,
       1058807808,
       1017593856,
       1057931264,
       1033199616,
       1057882112,
       1054064640,
       1058742272,
       1055858688,
       1058316288,
       1051058176,
       1060741120,
       1052385280,
       1060970496,
       1048231936,
       1060773888,
       1040261120,
       1059962880,
       1023836160,
       1059897344,
       1055481856,
       1037533184,
       1049812992,
       1038983168,
       1053564928,
       1045143552,
       1049812992,
       1044209664,
       1053564928,
       1050984448,
       1054760960,
       1053786112,
       1054760960,
       1050402816,
       1050566656,
       1054203904,
       1050566656,
       1054408704,
       1054212096,
       1057783808,
       1054760960,
       1054408704,
       1051402240,
       1057783808,
       1050951680,
       1057783808,
       1047633920,
       1054408704,
       1049313280,
       1061871616,
       1063313408,
       1059774464,
       1064599552,
       1061871616,
       1065312256,
       1059774464,
       1062993920,
       1061871616,
       1060036608,
       1059774464,
       1060364288,
       1059774464,
       1058750464,
       1061871616,
       1058021376,
       1059774464,
       1057677312,
       1061871616,
       1056415744,
       1059667968,
       1065312256,
       1059667968,
       1063387136,
       1057792000,
       1064443904,
       1057792000,
       1062895616,
       1059667968,
       1060904960,
       1057792000,
       1060904960,
       1057792000,
       1058906112,
       1059667968,
       1058422784,
       1057792000,
       1057341440,
       1059667968,
       1055989760,
       1054662656,
       1065312256,
       1057685504,
       1064394752,
       1054662656,
       1064198144,
       1057685504,
       1063501824,
       1054662656,
       1062322176,
       1057685504,
       1061994496,
       1057685504,
       1059291136,
       1054662656,
       1058963456,
       1057685504,
       1057783808,
       1054662656,
       1057079296,
       1057685504,
       1056841728,
       1054662656,
       1054998528,
       1035059200,
       1065312256,
       1019543552,
       1063870464,
       989544448,
       1063952384,
       1025736704,
       1061953536,
       1031020544,
       1062002688,
       1026195456,
       1058676736,
       1031495680,
       1058635776,
       1021534208,
       1056546816,
       1002119168,
       1056366592,
       1035755520,
       1053696000,
       1036656640,
       1054351360,
       1044701184,
       1054875648,
       1045577728,
       1054326784,
       1049501696,
       1057775616,
       1048854528,
       1057865728,
       1050050560,
       1060356096,
       1049387008,
       1060347904,
       1048764416,
       1062830080,
       1049411584,
       1062920192,
       1044389888,
       1064755200,
       1045250048,
       1065033728,
       1036001280,
       1064992768;
      }

      MeshVertexColors {
       104;
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
       103; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       1;
       84;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
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

       Material M_MedicalContainer {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "Stainless.jpg";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "sm_medicalcontainer";
       104;
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
       103;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
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
      {sm_medicalcontainer}

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
