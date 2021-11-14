package com.mygdx.game;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.maps.tiled.TiledMap;
import com.badlogic.gdx.maps.tiled.TiledMapTileLayer;
import com.badlogic.gdx.maps.tiled.TmxMapLoader;
import com.badlogic.gdx.maps.tiled.renderers.OrthogonalTiledMapRenderer;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;


public class MyGdxGame extends ApplicationAdapter {
	private OrthographicCamera cam;
	private TiledMap tilemap;
	private OrthogonalTiledMapRenderer tilemapRenderer;
	public float unitScale;
	private int[] tilemapLayers;
	private TiledMapTileLayer mainLayer;

	
	@Override
	public void create () {
		tilemap = new TmxMapLoader().load("testGrass.tmx");
		unitScale = 1/16f;
		tilemapLayers = new int[] {0};
		tilemapRenderer = new OrthogonalTiledMapRenderer(tilemap, unitScale);
		mainLayer = (TiledMapTileLayer) tilemap.getLayers().get(0);

		cam = new OrthographicCamera();
		cam.setToOrtho(false, mainLayer.getWidth(), mainLayer.getHeight());
		cam.update();
		tilemapRenderer.setView(cam);
		tilemapRenderer.render();

	}

	@Override
	public void render () {
		Gdx.gl.glClearColor(.25f, .60f, .25f, 1);
		Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
		cam.update();
		tilemapRenderer.render();
		tilemapRenderer.render(tilemapLayers);
	}
	
	@Override
	public void dispose () {
		tilemap.dispose();
		tilemapRenderer.dispose();

	}
}
