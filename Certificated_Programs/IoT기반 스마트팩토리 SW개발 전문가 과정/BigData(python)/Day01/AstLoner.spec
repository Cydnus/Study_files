# -*- mode: python ; coding: utf-8 -*-


block_cipher = None


a = Analysis(['AstLoner.ipynb'],
             pathex=['C:\\Users\\kccistc\\Desktop\\조상호\\Bigdata\\Day01'],
             binaries=[],
             datas=[],
             hiddenimports=['pygame'],
             hookspath=[],
             hooksconfig={},
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)

exe = EXE(pyz,
          a.scripts, 
          [],
          exclude_binaries=True,
          name='AstLoner',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          console=False,
          target_arch=None,
          codesign_identity=None,
          entitlements_file=None )
coll = COLLECT(exe,
               a.binaries,
               a.zipfiles,
               a.datas, 
               strip=False,
               upx=True,
               upx_exclude=[],
               name='AstLoner')
